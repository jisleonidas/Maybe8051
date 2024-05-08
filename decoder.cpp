#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>

#include "header.hpp"
#include "opcodes.hpp"

void read_bin(const char *fname, bool is_data)
{
    std::streampos size;
    char *memblock;

    std::ifstream file(fname, std::ios::in|std::ios::binary|std::ios::ate);
    if (file.is_open()) {
        size = file.tellg();
        memblock = new char [size];
        file.seekg (0, std::ios::beg);
        file.read (memblock, size);
        file.close();
    }

#ifdef DEBUG
    std::cout << "----------------------------------\n";
    std::cout << "READ BIN:\n";
    std::cout << "----------------------------------\n";
    if (!is_data)
        std::cout << "Loading " << std::setfill('0') << std::setw(4) << std::hex << (int) size
            << " bytes into code mem.\n";
    else
        std::cout << "Loading " << std::setfill('0') << std::setw(4) << std::hex << (int) size
            << " bytes into data mem.\n";
    for (int i = 0; i < size; i++) {
        if (!is_data) {
            code[i] = memblock[i];
            // std::cout << "Loading " << (int) code[i] << " into memory.\n";
        }
        else {
            data[i] = memblock[i];
            // std::cout << "Loading " << (int) data[i] << " into memory.\n";
        }
    }
    std::cout << "----------------------------------\n\n";
#endif

    delete[] memblock;
}

void run()
{

    std::cout << "----------------------------------\n";
    std::cout << "RUN PROGRAM:\n";
    std::cout << "----------------------------------\n";
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds

    while (pc < 65536) {
        sleep_for(milliseconds(500));
        unsigned char op = code[pc];
        std::cout << "PC: " << "0x" << std::setfill('0') << std::setw(2) << std::hex << pc << "; ";
        std::cout << "OP: " << "0x" << std::setfill('0') << std::setw(2) << std::hex << (int) op << "\n";
        // if (op == 0) {
        //     std::cout << "----------------------------------\n\n";
        //     return;
        // }
        // else
        (*lut[op])();
    }
    std::cout << "----------------------------------\n\n";
}