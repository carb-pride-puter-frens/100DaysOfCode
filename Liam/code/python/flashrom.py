import serial, time, os.path

PAGE_SIZE = 32

port = serial.Serial('COM3', 115200, timeout=2)
time.sleep(1)   #initializing
port.write(bytearray([0x4a]))   #flash command
print("Looking for 'rom.bin'...")
if os.path.exists("rom.bin"):
    with open("rom.bin", "rb") as romfile:
        print("File 'rom.bin' found. Writing flash...")
        size = os.path.getsize("rom.bin")
        i = 0
        while i < size:
            port.write(romfile.read(PAGE_SIZE))
            i += PAGE_SIZE
            port.flush()
    print(port.read(1)) #just used to make sure both the arduino and this script are still in sync. should output b'U'
    print("Finished!")
else:
    print("Error: file 'rom.bin' does not exist. Aborting.")