#include "mathcalc.h"
/*
operator order:

0 -> ( )
1 -> * / %
2 -> + -


idea:
stack1 keep numbers
stack2 keep operators

start when operator order changes
pop 2 elems from stack1
pop 1 elem from stack2
push 1 elem in stack1 
while (stack2!=empty)
*/

// op == operator, od == order
std::unordered_map<const char, const int8_t> opod{
    {'(', 0},
    {')', 0},
    {'*', 1},
    {'/', 1},
    // idk inca pt modulo ce sa fac da om vedea
    {'+', 2},
    {'-', 2}
};


std::string solve(std::string operand){
    std::string solution="", tempNumb="";
    
    std::stack<number> nums;
    std::stack<char> oper;
    for (auto chr:operand){
        if (isdigit(chr)){
            tempNumb.push_back(chr);
        } else {
            nums.push(number(tempNumb));
            tempNumb.clear();
            if (opod[oper.top()]>=opod[chr]){
                oper.push(chr);
            } else {
                // code to calculate the stuff in nums and oper
            }
        }
    }
    return solution;
}