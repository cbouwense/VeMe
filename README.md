# VeMe

## OpCode:

READ  |  `0 r`			|  Read the value stored at register r.
WRITE |  `1 r c`		|  Write value c to register r.
LOAD  |  `2 r m`		|  Load contents of memory address m to register r.
STORE |  `3 m r`		|  Store the contents of register r to memory address m.
PUSH  |  `4 r`			|  Push contents of register r onto the stack.
POP   |  `5 r`			|  Pop the stack and write the value in register r.
ADD   |  `6 r1 r2 r3`	|  Add contents of registers r1 and r2, store in register r3.
