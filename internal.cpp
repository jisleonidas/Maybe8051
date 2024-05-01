#include <iostream>
#include "header.hpp"

// ----------------------------------------
// PSWR STRUCTURE:
//  --- --- --- --- --- --- --- ---
// | 0 |   |   |   |   |   |   | C |
//  --- --- --- --- --- --- --- ---
//
// C - Carry flag
// ----------------------------------------

void dump_pswr()
{
    std::cout << "----------------------------------\n";
    std::cout << "DUMP PSWR:\n";
    std::cout << "----------------------------------\n";
    for (int i = 7; i >= 0; i--) {
        std::cout << std::hex << (int) ((pswr >> i) & 1) << " ";
    }
    std::cout << "\n----------------------------------\n\n";
}

void set_carry()
{
    pswr |= 1; // Set first bit to 1.
}