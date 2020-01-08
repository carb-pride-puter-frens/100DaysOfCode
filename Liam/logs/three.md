## Day 3 (1/7/2020)

3 hours spent

NOTE: Missed a day due to errands and work... Hopefully the only time this happens
Some final work on the chip flashing code for arduino. Dumping the chip and writing a rom file work, but cleanup is needed.
Python scripts for communicating with the arduino flasher are complete (and a lot simpler than I thought they would be).
Next steps: flashing some machine code to verify a working Z80 system, then familiarizing myself with Assembly.

Things to note in Arduino:
- memset() is a low level function capable of zeroing out an array, if it's a zeroable array.
- Serial.readBytes() will read directly into a buffer array and will stop after a timeout -- perfect for if you aren't sure of the length of data to receive!