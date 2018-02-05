/**
 * Main loop of processor
 * 
 * OPCODE:
 * 0 m1 m2: Read memory address m1 and store it in m2,
 * 1 c m    Write value c to memory address m.
 * 2 m1 m2: Add contents of memory addresses m1 and m2, store in m1
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
                       2, 0, 1, // Add the contents of mem addresses 0 and 1, store in 0
                       '\0'};

    vinit();

    vexec(program4);

    printNMem(1);

    return 0;
}