# VeMe  
A lightweight register-based virtual machine.

### OpCodes

READ: Read the value stored at register r.  
`0 r` 

WRITE: Write value c to register r.  
`1 r c` 

LOAD: Load contents of memory address m to register r.  
`2 r m`

STORE: Store the contents of register r to memory address m.  
`3 m r`

PUSH: Push contents of register r onto the stack.  
`4 r`

POP: Pop the stack and write the value in register r.  
`5 r`

ADD: Add contents of registers r1 and r2, store in register r3.  
`6 r1 r2 r3`

### Address Space & Memory Segments

VeMe is an 8-bit machine, so it has 256 memory addresses to work with. For its current, basic implentation, it can only run one process at a time; meaning, the entire address space is the memory segment for the currently running process. This memory segment is comprised of a text segment, a data segment, a heap, and a stack. The text segment and data segment are 32 bytes each; which means the heap grows up from address 0x40. 