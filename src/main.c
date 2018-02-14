/**
 *
 * OPCODE:
 * READ  |  0 r         |  Read the value stored at register r.
 * WRITE |  1 r c       |  Write value c to register r.
 * LOAD  |  2 r m       |  Load contents of memory address m to register r.
 * STORE |  3 m r       |  Store the contents of register r to memory address m.
 * PUSH  |  4 r         |  Push contents of register r onto the stack.
 * POP   |  5 r         |  Pop the stack and write the value in register r.
 * ADD   |  6 r1 r2 r3  |  Add contents of registers r1 and r2, store in register r3.
 * 
 */

#include "veme.h"

int main(int argc, char** argv) {

    byte program1[] = {
        1, 0, 10, // Write the value 10 to register 0
        0, 0,     // Read the value stored at register 0
        'e'       // EOF 
    };              

    byte program2[] = {
        1, 0, 10,   // Write the value of 10 to register 0
        1, 1, 20,   // Write the value of 20 to register 1
        6, 0, 1, 2, // Add the contents of registers 0 and 1, store in register 2
        'e'
    };

    vinit();
    vexec(program1);

    vinit();
    vexec(program2);
    printAllReg();

    return 0;
}
