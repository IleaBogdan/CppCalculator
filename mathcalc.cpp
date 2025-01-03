#pragma once
#include "mathcalc.h"
#include "number.h"

#define elif else if

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
std::unordered_map<char, int> opod{
    {'(', 0},
    {')', 0},
    {'*', 1},
    {'/', 1},
    // idk inca pt modulo ce sa fac da om vedea
    {'+', 2},
    {'-', 2}
};


void clearOper(std::stack<number> &nums, std::stack<char> &oper){
    while (!oper.empty()){
        char op=oper.top();
        oper.pop();
        number num1, num2;
        num2=nums.top(), nums.pop();
        num1=nums.top(), nums.pop();
        switch (op){
        case '+':
            nums.push(num1+num2);
            break;
        case '-':
            nums.push(num1-num2);
            break;
        case '*':
            nums.push(num1*num2);
            break;
        default:
            std::cout<<"TO DO"<<std::endl;
            break;
        }
    }
}
std::string solve(std::string operation){
    std::string tempNumb="";
    
    //std::cout<<operation<<std::endl;
    std::stack<number> nums;
    std::stack<char> oper;
    for (auto chr:operation){
        if (isdigit(chr)){
            tempNumb.push_back(chr);
        } else {
            nums.push(number(tempNumb));
            tempNumb.clear();
            if (oper.empty()){
                oper.push(chr);
            } elif (opod[oper.top()]>=opod[chr]){
                oper.push(chr);
            } else {
                clearOper(nums, oper);
                oper.push(chr);
            }
        }
    }
    nums.push(tempNumb);
    clearOper(nums, oper);
    return nums.top().to_string();
}