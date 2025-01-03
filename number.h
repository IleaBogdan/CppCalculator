#pragma once
#include <ostream>
#include <vector>
#include <algorithm>


// only works for int type numbers
// new implementation for float type to be added soon as a new class but first will make this one work
class number {
protected:
private:
    int _size;
    bool _sign;
    std::vector<short> _numb;

    void setValue(size_t i, int value);
    bool sign()const;
    int size()const;
    void push_back(int value);
    void pop_back();
    void clear();
    int operator[](size_t i)const;
    int back() const;
public:
    number();
    number(std::string numb);
    number(int numb);

    // <, >, <= and >= overload, will do afther testing if + works
    friend bool operator<(number num1, number num2);
    friend bool operator<=(number num1, number num2);
    friend bool operator<(number num1, int num2);
    friend bool operator<=(number num1, int num2);


    friend bool operator>(number num1, number num2);
    friend bool operator>=(number num1, number num2);
    friend bool operator>(number num1, int num2);
    friend bool operator>=(number num1, int num2);
    
    std::string to_string();
    




    // copy constructors for dumb bullshit
    number(const number& numb);
    number(const number& numb, bool sg);

    // absolute value
    number av();

    // calculus operators
    friend number operator-(number num1, number num2);
    friend number operator+(number num1, number num2); 
    

    number(std::vector<short> vec);
    
    friend bool operator==(number num1, number num2);

    friend number operator*(number num1, number num2);
    number operator++();
    // slow /
    // will do later a faster version
    friend number operator/(number num1, number num2);
    friend number operator/(number num1, number num2) {
        number num3;
        if (num2 == 0) {
            throw("division by 0 error");
            exit(0);
        }
        if (num2 > num1)return num3;
        num3._sign = (num1.sign() != num2.sign());
        num1 = num1.av(), num2 = num2.av();
        while (num1 >= num2) {
            //std::cout << num1 << " - " << num2 << std::endl;
            ++num3;
            num1 = num1 - num2;
        }
        //if (num1==num2)++num3;
        return num3;
    }
    friend std::ostream& operator<<(std::ostream& out, const number& numb) {
        if (numb._sign)out << '-';
        for (int i = numb._numb.size() - 1; i >= 0; --i) {
            out << numb._numb[i];
        }
        return out;
    }
};



/*
operator=


number &operator=(int numb)
{
    _numb.clear();
    do{
        _numb.push_back(numb%10);
        numb/=10;
    } while (numb);
    _size=_numb.size();
    return *this;
}
number &operator=(std::string numb)
{
    _numb.clear();
    _sign=bool(numb[0]=='-');
    if (_sign)numb[0]='0';
    for (auto it:numb){
        if (!isdigit(it)){
            throw("failed to convert nondigit to digit");
            exit(0);
        }
        _numb.push_back(it-'0');
    }
    std::reverse(_numb.begin(), _numb.end());
    while (_numb.back()==0)_numb.pop_back();
    _size=_numb.size();
    if (!_size){
        _sign=false;
        _numb={0};
        _size=1;
    }
    return *this;
}

*/