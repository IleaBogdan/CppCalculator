#include <iostream>
#include <string>
#include "mathcalc.h"

std::string input_reader(void) {
    std::string s;
    std::getline(std::cin, s);
    return s;
}
std::string calculate(const std::string& s) {
    std::string rezult;
    try {
        rezult = solve(s);
    }
    catch (char const* error) {
        rezult=std::string(error);
    }
    return rezult;
}
int main(void) {
    std::cout<<calculate(input_reader());
    return 0;
}