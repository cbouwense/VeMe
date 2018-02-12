### VeMe
###### Lightweight Virtual Machine.
---

### OpCode:

READ `0 m`
Read from memory address m.

WRITE `1 c m` 
Write value c to memory address m.

PUSH `2 c`
Push value c onto the stack. 

POP `3 m`
Pop the stack and store the value in m.

ADD `4 m1 m2 m3`
Add contents of m1 and m2, and store result in m3.
