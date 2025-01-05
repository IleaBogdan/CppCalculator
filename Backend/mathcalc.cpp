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

nvm it does not work as expected
*/
int orderNum=0;
std::string solve(std::string operation) {
    size_t i=0;
    ++orderNum;
    std::string newop;
    while (i<operation.size()){
        if (operation[i]=='('){
            int cnt=1;
            ++i;
            std::string newsolve="";
            for (; i<operation.size() && cnt; ++i){
                cnt+=bool(operation[i]=='(')-bool(operation[i]==')');
                newsolve.push_back(operation[i]);
            }
            if (newsolve.back()==')'){
                newsolve.pop_back();
                --i;
            }
            //std::cout<<orderNum<<": - "<<newsolve<<std::endl;
            newop+=solve(newsolve);
            //std::cout<<newop<<std::endl;
        } else newop.push_back(operation[i]);
        ++i;
    }
    // no more * and /
    i=0;
    std::string newnewop;
    while (i<newop.size()){
        if (newop[i]=='*' || newop[i]=='/'){
            char keepsign=newop[i];
            std::string temp;
            while (!newnewop.empty() && isdigit(newnewop.back())){
                temp.push_back(newnewop.back());
                newnewop.pop_back();
            }
            std::reverse(temp.begin(), temp.end());
            number num1(temp);
            temp.clear();
            ++i;
            while (i<newop.size() && isdigit(newop[i])){
                temp.push_back(newop[i]);
                ++i;
            }
            if (i!=newop.size())--i;
            if (keepsign=='*'){
                std::string hs=(num1*number(temp)).to_string();
                newnewop+=hs;
            } else {
                std::string hs=(num1/number(temp)).to_string();
                newnewop+=hs;
            }
        } else {
            newnewop.push_back(newop[i]);
        }
        ++i;
    }
    // no more + and -
    i=0;
    std::string rez;
    while (i<newnewop.size()){
        if (newnewop[i]=='+' || newnewop[i]=='-'){
            char keepsign=newop[i];
            std::string temp;
            number num1(rez);
            temp.clear();
            ++i;
            while (i<newnewop.size() && isdigit(newnewop[i])){
                temp.push_back(newnewop[i]);
                ++i;
            }
            if (i!=newnewop.size())--i;
            if (keepsign=='+'){
                std::string hs=(num1+number(temp)).to_string();
                rez=hs;
            } else {
                std::string hs=(num1-number(temp)).to_string();
                rez=hs;
            }
        } else {
            rez.push_back(newnewop[i]);
        }
        ++i;
    }
    return rez;
}