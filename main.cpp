#include <iostream>


#include "mathcalc.h"

std::string input_reader(){
    std::string s;
    std::getline(std::cin, s);
    return s;
}
int main(){
    std::cout<<solve(input_reader());
    return 0;
}