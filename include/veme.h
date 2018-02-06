#pragma once

typedef unsigned char byte;

void vinit();
byte vread(byte maddr);
void vwrite(byte val, byte maddr);
void vadd(byte m1, byte m2, byte m3);
void printMem();
void printNMem(byte highest);
void vexec(byte* program);
