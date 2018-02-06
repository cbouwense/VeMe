#include <stdio.h>
#include <stdlib.h>
#include "veme.h"

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

void vadd(byte m1, byte m2) {
    byte op1 = vread(m1);
    byte op2 = vread(m2);
    vwrite(op1+op2, m1);
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
    byte op1, op2, val, maddr1, maddr2;
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
                maddr1 = program[++linePos];
                vwrite(val, maddr1);
                break;
            // Add
            case 2:
                maddr1 = program[++linePos];
                maddr2 = program[++linePos];
                vadd(maddr1, maddr2);
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
