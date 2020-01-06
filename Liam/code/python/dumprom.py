import serial, time, os

PAGE_SIZE = 32

port = serial.Serial('COM3', 115200, timeout=2)
time.sleep(1)   #initializing
port.write(bytearray([0x3a]))   #dump command
print("Dumping flash...")
if os.path.exists("dump.bin"):
    os.remove("dump.bin")
with open("dump.bin", "ab") as dumpfile:
    page = bytearray([0])
    while len(page) > 0:
        page = port.read(PAGE_SIZE)    #reads in pages to prevent buffer clog
        dumpfile.write(page)
print("Finished!")