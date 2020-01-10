## Day 5 (1/9/2020)

2 hours spent

Wrote a basic program in machine code to jump back and forth between two addresses. This is to visually test the processor and flash chip readability through address line LEDs. I also spent a good deal of time reading the instruction opcodes from the datasheet and doing basic wiring, but I think they should be counted for time since it is vital to continuing.
- I will probably not upload any raw binary roms to this repo, since uploading assembly will be much cleaner and easier to read/manipulate.

Things to note:
- vasm, a very common assembler that supports the Z80 I'm using, will need to be built from source. I'm hoping I can use VS Code in some way to facilitate that in Windows, otherwise I'll have to work on the next part in Linux
- opcodes (at least for the Z80) are generally one byte, and depending on how much data needs to be read per opcode, the execution of the instruction might take several clock cycles from initial read