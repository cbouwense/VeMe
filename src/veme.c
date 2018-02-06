#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 256

typedef unsigned char byte;

byte* memory;

void vinit() {
    // Allocate memory and zero it out
    memory = calloc(MEM_SIZE, MEM_SIZE);
}

// Returns value held at mem address maddr
byte vread(byte maddr) {
    return memory[maddr];
}

void vwrite(byte val, byte maddr) {
    memory[maddr] = val;
}

void vadd(byte m1, byte m2, byte m3) {
    byte op1 = vread(m1);
    byte op2 = vread(m2);
    vwrite(op1+op2, m3);
}

void printMem() {
    for (byte i = 0; i < MEM_SIZE; i++) {
        printf("memory[%d]: %d\n", i, memory[i]);
        // Have to do this because counter overflows lol
        if (i == MEM_SIZE-1)
            break;
    }
}

void printNMem(byte highest) {
    for (byte i = 0; i <= highest; i++) {
        printf("memory[%d]: %d\n", i, memory[i]);
        // Have to do this because counter overflows lol
        if (i == MEM_SIZE-1)
            break;
    }
}

void vexec(byte* program) {
    byte op1, op2, val, m1, m2, m3;
    byte linePos = 0;
    while (program[linePos] != '\0') {
        switch (program[linePos]) {
            // Read
            case 0:
                // TODO: this probably shouldn't just print lol
		printf("%d\n", vread(program[++linePos]));
                break;
            // Write
            case 1:
                val = program[++linePos];
                m1 = program[++linePos];
                vwrite(val, m1);
                break;
            // Add
            case 2:
                m1 = program[++linePos];
                m2 = program[++linePos];
                m3 = program[++linePos];
                vadd(m1, m2, m3);
                break;
            default:
                printf("Error occured at %d\n", linePos);
                printf("Invalid input %d detected\n", program[linePos]);
                exit(1);
        }
        linePos++;
    }
    printf("Program executed successfully\n");
}
