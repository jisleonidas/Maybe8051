#include <iostream>
#include <iomanip>
#include <cstdint>

#include "header.hpp"
#include "decoder.hpp"
#include "internal.hpp"

void dump()
{
    std::cout << "----------------------------------\n";
    std::cout << "DUMPING REGISTER CONTENTS:\n";
    std::cout << "----------------------------------\n";
    std::cout << "A : " << "0x" << std::hex << (int) a << "\n";
    std::cout << "B : " << "0x" << std::hex << (int) b << "\n";

    for (int i = 0; i < 8; i++) {
        std::cout << "R" << i << ": " << "0x" << std::hex << (int) *(r[i]) << "\n";
    }

    std::cout << "DPTR: " << "0x" << std::hex << (int) dptr << "\n";

    std::cout << "----------------------------------\n\n";
}

void dump_ram()
{
    std::cout << "----------------------------------\n";
    std::cout << "DUMPING RAM CONTENTS:\n";
    std::cout << "----------------------------------\n";
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << std::setfill('0') << std::setw(2) << std::hex << (int) ram[i*8+j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "----------------------------------\n\n";
}

int main()
{
    dump();
    read_bin("main.bin", false);
    read_bin("data.bin", true);
    run();
    dump();
    dump_ram();
    dump_pswr();

    std::cout << "Exited!\n";

    return 0;
}