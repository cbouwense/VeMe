#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 256
#define REG_NO 10
// TODO: Is this even good practice
#define stackPtr registers[REG_NO-1]
// TODO: Do we actually need an instruction pointer?
#define instrPtr registers[REG_NO-2]
#define NEXT_TOKEN program[++linePos]

typedef unsigned char byte;

byte* memory;
byte registers[REG_NO];

/* Register Operations */

// TODO: Is this really all read should do?
void vread(byte regNo) {
    printf("%i\n", registers[regNo]);
}

// TODO: Check regNo bounds
void vwrite(byte regNo, byte val) {
    registers[regNo] = val;
}

/* Memory Operations */

void vload(byte regNo, byte maddr) {
    registers[regNo] = memory[maddr];
}

void vstore(byte maddr, byte regNo) {
    memory[maddr] = registers[regNo];
}

void vadd(byte r1, byte r2, byte r3) {
    // TODO: Should I refactor this so that you use read?
    byte op1 = registers[r1];
    byte op2 = registers[r2];
    vwrite(r3, op1+op2);
}

/* Stack Operations */
// TODO: I should probably check for overflow/underflow
//       but I also think it could be cool to leave them in.

void vpush(byte regNo) {
    memory[stackPtr] = registers[regNo];
    stackPtr--;
}

byte vpop(byte regNo) {
    registers[regNo] = memory[++stackPtr];
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
    
    byte op1, op2, val, m1, m2, r1, r2, r3;
    byte linePos = 0;

    while (program[linePos] != 'e') {
        switch (program[linePos]) {
            // READ
            case 0:
                r1 = NEXT_TOKEN;
                vread(r1);
                break;
            // WRITE
            case 1: 
                r1 = NEXT_TOKEN;
                val = NEXT_TOKEN;
                vwrite(r1, val);
                break;
            // LOAD
            case 2:
                r1 = NEXT_TOKEN;
                m1 = NEXT_TOKEN;
                vload(r1, m1);
                break;
            // STORE
            case 3:
                m1 = NEXT_TOKEN;
                r1 = NEXT_TOKEN;
                vstore(m1, r1);
                break;
            // PUSH
            case 4:
                r1 = NEXT_TOKEN;
                vpush(r1);
                break;
            // POP
            case 5:
                r1 = NEXT_TOKEN;
                vpop(r1);
                break;
            // ADD
            case 6:
                r1 = NEXT_TOKEN;
                r2 = NEXT_TOKEN;
                r3 = NEXT_TOKEN;
                vadd(r1, r2, r3);
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

void printMem() {
    for (byte i = 0; i < MEM_SIZE; i++) {
        printf("memory[%d]: %d\n", i, memory[i]);
        // Have to do this because counter overflows lol
        if (i == MEM_SIZE-1)
            break;
    }
}

void printNMem(byte addresses) {
    for (byte i = 0; i < addresses; i++) {
        printf("memory[%d]: %d\n", i, memory[i]);
        // Have to do this because counter overflows lol
        if (i == MEM_SIZE-1)
            break;
    }
}

void printReg(byte regNo) {
    printf("reg %i: %i\n", regNo, registers[regNo]);
}

void printAllReg() {
    for (byte i = 0; i < REG_NO; i++) {
        printReg(i);
    }
}