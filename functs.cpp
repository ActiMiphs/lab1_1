
#include "functs.h"
#include "sequence.h"
#include <cstdlib>

#include <iostream>

int getNumber() {
    int number;
    while (true) {
        std::cin >> number;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Error! Enter a number: ";
        } else {
            std::cin.ignore(32767, '\n');
            return number;
        }
    }
}

