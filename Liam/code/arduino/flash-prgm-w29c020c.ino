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

//Variables to use as registers, but not to be altered directly!
byte data = 0;
word addr = 0;

void set_address(word new_addr) {
  addr = new_addr;
  for (int i = 0; i < sizeof(addr_pins); i++) {
    digitalWrite(addr_pins[i], new_addr & 1);
    new_addr = new_addr >> 1;
  }
}

void read_byte(word address) {
  digitalWrite(WE, HIGH);
  set_address(address);
  digitalWrite(CE, LOW);
  digitalWrite(OE, LOW);
  data = 0;
  for (int i = 7; i > -1; i--) {
    data = data + digitalRead(data_pins[i]);
    data = data << 1;
  }
  digitalWrite(CE, HIGH);
  digitalWrite(OE, HIGH);
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
  Serial.println("Connected!");
  //things to do next
}

void loop() {
  
}
