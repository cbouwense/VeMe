#pragma once

typedef unsigned char byte;

/* Register Operations */

// Print the value stored in a register
void vread(byte regNo);
// Write a value to a register
void vwrite(byte regNo, byte val);

/* Memory Operations */

// Load a the value stored in a memory address into a register
void vload(byte regNo, byte maddr);
// Store a value stored in a register to a memory address
void vstore(byte maddr, byte regNo);

/* Stack Operations */

// Push a value in a register onto the stack
void vpush(byte regNo);
// Pop the stack and store in a register
byte vpop(byte regNo);

/* Mathematical & Logic Operations */

// Add the contents of two registers and store it in the third
void vadd(byte r1, byte r2, byte r3);

/* Control Flow Operations */


/* Meta Operations */

// Initialize the system: zero out memory, etc.
void vinit();
// Execute a program
void vexec(byte* program);
// Print the entire contents of memory
void printMem();
// Print N contents of memory starting from 0
void printNMem(byte highest);
// Print a specific register
void printReg(byte regNo);
// Print all registers
void printAllReg();