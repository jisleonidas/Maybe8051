#include <cstdint>
#include <iostream>
#include "header.hpp"
#include "internal.hpp"

void nop()
{
    pc++;
}

// Todo
void ajmp()
{
    pc++;
    pc++;
}

void ljmp()
{
    pc++;
    char high_byte = code[pc];
    pc++;
    char low_byte = code[pc];
    pc = ((int) high_byte) << 8;
    pc += (int) low_byte;
}

void rr_a()
{
    if (a << 7)
        a = (a >> 1) + 128;
    else
        a = (a >> 1);
    pc++;
}

// No carry set when value rolls over from 255 to 0.
void inc_a()
{
    a += 1;
    pc++;
}

void inc_direct()
{
    pc++;
    int loc = code[pc];
    ram[loc]++;
    pc++;
}

void inc_atr0()
{
    ram[*(r[0])]++;
    pc++;
}

void inc_atr1()
{
    ram[*r[1]]++;
    pc++;
}

void inc_r0()
{
    (*r[0])++;
    pc++;
}

void inc_r1()
{
    (*r[1])++;
    pc++;
}

void inc_r2()
{
    (*r[2])++;
    pc++;
}

void inc_r3()
{
    (*r[3])++;
    pc++;
}

void inc_r4()
{
    (*r[4])++;
    pc++;
}

void inc_r5()
{
    (*r[5])++;
    pc++;
}

void inc_r6()
{
    (*r[6])++;
    pc++;
}

void inc_r7()
{
    (*r[7])++;
    pc++;
}

void jbc()
{
    pc += 3;
}

void acall()
{
    pc += 2;
}

void lcall()
{
    pc += 3;
}

void rrc_a()
{
    pc++;
}

void dec_a()
{
    a--;
    pc++;
}

void dec_direct()
{
    pc++;
    int loc = code[pc];
    ram[loc]--;
    pc++;
}

void dec_atr0()
{
    ram[*(r[0])]--;
    pc++;
}

void dec_atr1()
{
    ram[*r[1]]--;
    pc++;
}

void dec_r0()
{
    (*r[0])--;
    pc++;
}

void dec_r1()
{
    (*r[1])--;
    pc++;
}

void dec_r2()
{
    (*r[2])--;
    pc++;
}

void dec_r3()
{
    (*r[3])--;
    pc++;
}

void dec_r4()
{
    (*r[4])--;
    pc++;
}

void dec_r5()
{
    (*r[5])--;
    pc++;
}

void dec_r6()
{
    (*r[6])--;
    pc++;
}

void dec_r7()
{
    (*r[7])--;
    pc++;
}

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
    nop,
    ajmp,
    ljmp,
    rr_a,
    inc_a,
    inc_direct,
    inc_atr0,
    inc_atr1,
    inc_r0,
    inc_r1,
    inc_r2,
    inc_r3,
    inc_r4,
    inc_r5,
    inc_r6,
    inc_r7,
    jbc,
    acall,
    lcall,
    rrc_a,
    dec_a,
    dec_direct,
    dec_atr0,
    dec_atr1,
    dec_r0,
    dec_r1,
    dec_r2,
    dec_r3,
    dec_r4,
    dec_r5,
    dec_r6,
    dec_r7,
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