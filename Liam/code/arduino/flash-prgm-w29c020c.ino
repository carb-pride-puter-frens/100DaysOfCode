/*
WIP!!!

This code is specifically for programming a Winbond W29C020C-90B,
via an Arduino Mega 2560, but might also work with other flash chips.
Only the first 15 address bits are used because only 32k of the flash
storage is needed for this project.
*/

//Pin definitions
byte CE = 52; //active low
byte OE = 53; //active low
byte WE = 51; //active low
byte data_pins[] = {31,32,33,44,43,42,41,40}; //D0 first, D7 last
byte addr_pins[] = {30,29,28,27,26,25,24,23,48,47,45,46,22,49,50}; //A0 first, A14 last
word max_addr = pow(2, sizeof(addr_pins)); //just over the highest address value possible
byte page[128]; //page buffer for flash chip, datasheet specifies 128 bytes

//Variables to use as registers, but not to be altered directly in the main loop!
byte data = 0;
word addr = 0;

//writes address to addr pins
void set_address(word address) {
  addr = address;
  for (int i = 0; i < sizeof(addr_pins); i++) {
    digitalWrite(addr_pins[i], address & 1);
    address = address >> 1;
  }
}

//writes ndata to data pins
void set_data(byte ndata) {
  data = ndata;
  for (byte i = 0; i < 8; i++) {
    digitalWrite(data_pins[i], ndata & 1);
    ndata = ndata >> 1;
  }
}

//loads data pin states into data register
void load_data() {
  data = 0;
  for (int i = 7; i > -1; i--) {
    data = data << 1;
    data = data + digitalRead(data_pins[i]);
  }
}

//sets data pins to input mode for reading
void set_pins_input() {
  for (byte i = 0; i < 8; i++) {
    pinMode(data_pins[i], INPUT);
  }
}

//sets data pins to output mode for writing
void set_pins_output() {
  for (byte i = 0; i < 8; i++) {
    pinMode(data_pins[i], OUTPUT);
  }
}

//reads a byte from the specified address
void read_byte(word address) {
  digitalWrite(OE, LOW);
  set_address(address);
  digitalWrite(WE, HIGH);
  digitalWrite(CE, LOW);
  load_data();
  digitalWrite(CE, HIGH);
  digitalWrite(OE, HIGH);
}

//writes a byte to a specified address
//USE write_page WHEN FLASHING! The chip uses a page write cycle, so
//writing a single byte will set the other bytes in the page to 0xFF!
void write_byte(word address, byte ndata) {
  set_address(address);
  //delayMicroseconds(1);
  digitalWrite(OE, HIGH);
  digitalWrite(CE, LOW);
  digitalWrite(WE, LOW); //address is latched here
  set_data(ndata);
  //delayMicroseconds(1);
  digitalWrite(WE, HIGH); //data is latched here
  digitalWrite(CE, HIGH);
  digitalWrite(OE, LOW);
  //delayMicroseconds(1);
}

//sends command to chip. refer to datasheet for codes
void rom_command(byte cmd) {
  write_byte(0x5555, 0xAA);
  write_byte(0x2AAA, 0x55);
  write_byte(0x5555, cmd);
}

//writes a page of 128 bytes to the chip at the specified address
//NOTE: address ignores the first 7 bits because of page size, and
void write_page(word address) {
  rom_command(0xA0); //software write protection
  address = address & 0xFF80; //ignore first 7 bits
  for (byte i = 0; i < 128; i++) { //only read the first 128 bytes
    write_byte(address + i, page[i]);
  }
  delay(11); //internal write cycle datasheet specifies a max of 10ms, adding another 1ms for the 200us byte load cycle time
}

//erases all data on the chip
void erase_chip() {
  rom_command(0x80);
  rom_command(0x10);
  delay(50); //internal write cycle, datasheet specifies 50ms
}

//reads all bytes up to the specified max_addr from the chip
void dump_rom() {
  for (word address = 0; address < max_addr; address = address + 32) {
    for (byte i = 0; ((i < 32) && (address + i < max_addr)); i++) {
      read_byte(address + i);
      Serial.write(data);
    }
    Serial.flush(); //writing in 32 byte sections like this prevents clogging the serial buffer
  }
}

//writes as many bytes to the rom from the starting address as are sent over, under the maximum address
void flash_rom() {
  //loop to build pages and write them until rom_length amount of bytes have been written
  Serial.setTimeout(500);
  word address = 0;
  boolean more_bytes = true;
  while (more_bytes && (address < max_addr)) {
    memset(page, 0, 128); //zero out page buffer
    byte num_bytes = Serial.readBytes(page, 128);
    if (num_bytes == 0) {
      more_bytes = false;
    } else {
      write_page(address);
      address = address + 128;
    }
  }
  //send ok message to verify complete write
  Serial.write(0x55);
  Serial.flush();
}

//obtains product identification codes
void get_rom_info() {
  set_pins_output();
  rom_command(0x80);
  rom_command(0x60);
  delayMicroseconds(15);
  set_pins_input();
  for (byte i = 0; i < 3; i++) {
    read_byte(i);
    Serial.write(data);
  }
  //exit identification mode
  set_pins_output();
  rom_command(0xF0);
  delayMicroseconds(15);
}

void setup() {
  pinMode(CE, OUTPUT);
  pinMode(OE, OUTPUT);
  pinMode(WE, OUTPUT);
  digitalWrite(CE, HIGH);
  digitalWrite(OE, HIGH);
  digitalWrite(WE, HIGH);
  for (int i = 0; i < sizeof(addr_pins); i++) {    //sizeof works fine here because it is an array of bytes
    pinMode(addr_pins[i], OUTPUT);
    digitalWrite(addr_pins[i], LOW);
  }
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {
    byte cmd = Serial.read();
    if (cmd == 0x3A) {
      //dump the rom
      set_pins_input();
      dump_rom();
    } else if (cmd == 0x4A) {
      //flash the rom
      set_pins_output();
      flash_rom();
    } else if (cmd == 0x5A) {
      //erase the rom
      set_pins_output();
      erase_chip();
    } else if (cmd == 0x6A) {
      //Delete later, only used for testing!
      set_pins_output();
      rom_command(0xA0); //software write protection
      write_byte(0x0000, 0x30);
    } else if (cmd == 0x7A) {
      //get chip info
      get_rom_info();
    }
    Serial.flush();
  }
}
