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

    friend std::ostream& operator<<(std::ostream& out, const number& numb);
};
