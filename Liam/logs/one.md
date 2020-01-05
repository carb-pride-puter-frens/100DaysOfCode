## Day 1 (1/4/2020)

2 hours spent

Began organizing my files and directories in the repo, loosely based on Michael Bailey's setup. 
Worked on arduino code for flashing a W29C020C flash IC to facilitate working with assembly on 8-bit hardware.

Things to note in Arduino:
- sizeof() will return the length of an array in bytes, but if your array is of bytes already, the output is the number of elements!
- bit shifting a numeric does NOT loop bits. aka: 10110010 << 2 gives you 11001000
- arrays are instantiated with int myarray[] = {}, but can also be instantiated by int myarray[size]
