#include <iostream>
#include <string>
#include "mathcalc.h"

std::string input_reader(void) {
    std::string s;
    std::getline(std::cin, s);
    return s;
}
int mainback(void){
    try {
        std::cout << "fullrez: "+ solve(input_reader());
    }
    catch (char const* error) {
        std::cout << error;
    }
    return false;
}