#pragma once

// libs
#include <string>
#include <stack>
#include <unordered_map>
#include <iostream>

// files
#include "number.h"

void clearOper(std::stack<number>& nums, std::stack<char>& oper);
std::string solve(std::string);