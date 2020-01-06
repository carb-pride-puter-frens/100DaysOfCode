import serial, time, os.path

PAGE_SIZE = 4

port = serial.Serial('COM3', 115200, timeout=2)
print("Connecting")
time.sleep(1)   #initializing
port.write(bytearray([0x4a]))   #dump command
print("Looking for 'rom.bin'...")
if os.path.exists("rom.bin"):
    with open("rom.bin", "rb") as romfile:
        print("File 'rom.bin' found. Writing flash...")
        size = os.path.getsize("rom.bin")
        for i in range(0, 4, 1):
            
        i = 0
        while i < size:
            port.write(romfile.read(PAGE_SIZE))
            i += PAGE_SIZE
            port.flush()
    print("Finished!")
else:
    print("Error: file 'rom.bin' does not exist. Aborting.")