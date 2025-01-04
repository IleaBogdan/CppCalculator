#include <iostream>
#include <string>
#include "mathcalc.h"

std::string input_reader(void) {
    std::string s;
    std::getline(std::cin, s);
    return s;
}
void mainback(void){
    try {
        std::cout << solve(input_reader());
    }
    catch (char const* error) {
        std::cout << error;
    }
}