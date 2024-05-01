#include <cstdint>
#include "header.hpp"
#include "internal.hpp"

void mov_a_data()
{
    pc++; a = code[pc]; pc++;
}

void mov_b_data()
{
    pc++; b = code[pc]; pc++;
}

void mov_r0_data()
{
    pc++; *(r[0]) = code[pc]; pc++;
}

void mov_r1_data()
{
    pc++; *(r[1]) = code[pc]; pc++;
}

void mov_r2_data()
{
    pc++; *(r[2]) = code[pc]; pc++;
}

void mov_r3_data()
{
    pc++; *(r[3]) = code[pc]; pc++;
}

void mov_r4_data()
{
    pc++; *(r[4]) = code[pc]; pc++;
}

void mov_r5_data()
{
    pc++; *(r[5]) = code[pc]; pc++;
}

void mov_r6_data()
{
    pc++; *(r[6]) = code[pc]; pc++;
}

void mov_r7_data()
{
    pc++; *(r[7]) = code[pc]; pc++;
}

void add_a_data()
{
    int old_a = a;
    pc++;
    a += code[pc];
    if (a < old_a)
        set_carry();
    pc++;
}

void push_a()
{
    sp++;
    ram[sp] = a;
    pc++;
}

void pop_a()
{
    a = ram[sp];
    sp--;
    pc++;
}

void mov_dptr_data()
{
    pc++;
    dptr |= (unsigned int)(code[pc]) << 8;
    pc++;
    dptr |= (unsigned int)(code[pc]);
    pc++;
}

void movx_a_dptr()
{
    a = data[dptr];
    pc++;
}

void movx_dptr_a()
{
    data[dptr] = a;
    pc++;
}

void inc_dptr()
{
    dptr++;
    pc++;
}

void sjmp()
{
    pc++;
    signed char offset = (signed char) code[pc];
    pc += offset+1;
}

void mul_ab()
{
    a *= b;
    pc++;
}

void div_ab()
{
    unsigned char quo, rem;
    if (b != 0) {
        quo = a / b;
        rem = a % b;
    }
    a = quo;
    b = rem;
    pc++;
}

void empty() {}

void (*lut[])() = {
    empty,
    mov_a_data,
    mov_b_data,
    mov_r0_data,
    mov_r1_data,
    mov_r2_data,
    mov_r3_data,
    mov_r4_data,
    mov_r5_data,
    mov_r6_data,
    mov_r7_data,
    add_a_data,
    empty, // ADD A, B
    empty, // ADD A, R0
    empty, // ADD A, R1
    empty, // ADD A, R2
    empty, // ADD A, R3
    empty, // ADD A, R4
    empty, // ADD A, R5
    empty, // ADD A, R6
    empty, // ADD A, R7
    push_a,
    pop_a,
    mov_dptr_data,
    movx_a_dptr,
    movx_dptr_a,
    inc_dptr,
    sjmp,
    mul_ab,
    div_ab,
    // empty,
};