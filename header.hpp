#ifndef HEADER_H
#define HEADER_H

extern unsigned char code[65536]; // 8 bit values. 2^16 memory locations. So 65536 bytes.
extern unsigned char data[65536];
extern unsigned char ram[128];

extern unsigned char pswr;
extern unsigned char sp;

extern unsigned int pc; // Program counter
extern unsigned int dptr; // Data pointer

extern unsigned char a; // Accumulator
extern unsigned char b; // Multiply and divide

extern unsigned char *r[8];

#endif