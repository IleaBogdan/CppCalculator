#include <iostream>


#include "mathcalc.h"

std::string input_reader() {
    std::string s;
    std::getline(std::cin, s);
    return s;
}
int main() {
    try {
        std::cout << solve(input_reader());
    }
    catch (char const* error) {
        std::cout << error;
    }
    return 0;
}