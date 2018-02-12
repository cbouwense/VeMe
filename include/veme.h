#pragma once

typedef unsigned char byte;

// Memory Operations
byte vread(byte maddr);
void vwrite(byte val, byte maddr);

// Stack Operations
void vpush(byte val);
byte vpop();

// Mathematical / Logic Operations
void vadd(byte m1, byte m2, byte m3);

// Control Flow Operations

// Meta Operations
void vinit();
void vexec(byte* program);

// Misc.
void printMem();
void printNMem(byte highest);
