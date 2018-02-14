# VeMe

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