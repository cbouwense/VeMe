/**
 *
 * OPCODE:
 * READ  |  0 m1 m2     |  Read memory address m1 and store it in m2,
 * WRITE |  1 c m       |  Write value c to memory address m.
 * PUSH  |  2 c         |  Push value c onto the stack.
 * POP   |  3 m         |  Pop the stack and store the value in address m.
 * ADD   |  4 m1 m2 m3  |  Add contents of memory addresses m1 and m2, store in m3
 * 
 */

#include "veme.h"

int main(int argc, char** argv) {

    byte program1[] = {0, 2,    // Read memory address 2
                       '\0'};

    byte program2[] = {1, 5, 0, // Write the value of 5 to mem address 0
                       0, 0,    // Read mem address 0
                       '\0'};

    byte program3[] = {1, 5, 0, // Write 5 to maddr 0
                       1, 6, 1, // Write 6 to maddr 1
                       '\0'};

    byte program4[] = {1, 5, 0, // Write the value of 5 to mem address 0
                       1, 6, 1, // Write the value of 6 to mem address 1
                       2, 0, 1, 2, // Add the contents of mem addresses 0 and 1, store in 2
                       '\0'};

    byte program5[] = {2, 3,    // Push the value of 3 onto the stack
                       '\0'};

    byte program6[] = {2, 3,    // Push the value of 3 onto the stack
                       2, 4,    // Push the value of 4 onto the stack
                       3, 0,    // Pop the stack and store the result at mem address 0
                       3, 1,    // Pop the stack and store the result at mem address 1
                       4, 0, 1, 2, // Add the contents of mem addresses 0 and 1, and store the results in mem address 2
                       '\0'};

    /*
    vinit();
    vexec(program1);

    vinit();
    vexec(program2);
    printNMem(0);

    vinit();
    vexec(program3);
    printNMem(1);    

    vinit();
    vexec(program4);
    printNMem(2);
    
    vinit();
    vexec(program5);
    printMem();
    */

    vinit();
    vexec(program6);
    printMem();

    return 0;
}
