#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 256

typedef unsigned char byte;

byte* memory;
byte stackPtr;
// TODO: Do we actually need an instruction pointer?
byte instrPtr;

/* Memory Operations */

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

/* Stack Operations */

void vpush(byte val) {
    // TODO: I'm should probably check for overflow

    memory[stackPtr] = val;
    stackPtr--;
}

byte vpop() {
    // This is the soyboy implementation that checks for underflow
    /*
    byte val = 0;
    if (stackPtr < MEM_SIZE) {
        val = memory[stackPtr];
    }
    else {
        printf("Nothing on stack to pop, exiting.");
        exit(1);
    }
    return val;
    */

    // This is the alpha implementation that doesn't care about underflow
    return memory[++stackPtr];
}

/* Meta Operations */

void vinit() {
    // Allocate memory and zero it out
    memory = calloc(MEM_SIZE, MEM_SIZE);
    stackPtr = MEM_SIZE-1;
    // TODO: Should this actually be zero?
    instrPtr = 0;
}

void vexec(byte* program) {
    byte op1, op2, val, m1, m2, m3;
    byte linePos = 0;
    while (program[linePos] != '\0') {
        switch (program[linePos]) {
            // READ
            case 0:
                // TODO: this probably shouldn't just print lol
		printf("%d\n", vread(program[++linePos]));
                break;
            // WRITE
            case 1:
                val = program[++linePos];
                m1 = program[++linePos];
                vwrite(val, m1);
                break;
            // PUSH
            case 2:
                val = program[++linePos];
                vpush(val);
                break;
            // POP
            case 3:
                m1 = program[++linePos];
                val = vpop();
                vwrite(val, m1);
                break;
            // ADD
            case 4:
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

/* Misc Operations */

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

