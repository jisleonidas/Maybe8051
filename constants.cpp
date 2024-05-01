unsigned char code[65536] = {0}; // 8 bit values. 2^16 memory locations. So 65536 bytes.
unsigned char data[65536] = {0};
unsigned char ram[128] = {0};

unsigned char pswr = 0;
unsigned char sp = 7;

unsigned int pc = 0; // Program counter
unsigned int dptr = 0; // Data pointer

unsigned char a = 0; // Accumulator
unsigned char b = 0; // Multiply and divide

unsigned char *r[8] = {&ram[0], &ram[1], &ram[2], &ram[3], &ram[4], &ram[5], &ram[6], &ram[7]};