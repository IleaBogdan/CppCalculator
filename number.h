#pragma once
#include <ostream>
#include <vector>
#include <algorithm>


// only works for int type numbers
// new implementation for float type to be added soon as a new class but first will make this one work
class number{
private:
    int _size;
    bool _sign;
    std::vector<short> _numb;
    
    int operator[](int i){
        return _numb[i];
    }
    bool sign()
    {
        return _sign;
    }
    int size(){
        return _size;
    }
    void push_back(int value){
        _numb.push_back(value);
        ++_size;
    }
    void clear()
    {
        _numb.clear();
        _sign=false;
        _size=0;
    }
public:
    number(){
        _numb={0};
        _size=1;
        _sign=false;
    }
    number(std::string numb){
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
    }
    number(int numb){
        _sign=bool(numb<0);
        numb=abs(numb);
        do{
            _numb.push_back(numb%10);
            numb/=10;
        } while (numb);
        _size=_numb.size();
    }


    // <, >, <= and >= overload, will do afther testing if + works
    friend bool operator<(number num1, number num2)
    {
        if (num1._sign && !num2._sign)return true;
        if (!num1._sign && num2._sign)return false;
        bool sign=num1._sign;
        if (num1.size()!=num2.size()) return (sign ? num1.size()>num2.size() : num1.size()<num2.size());
        for (size_t i=num1.size(); i>=0; --i){
            if (num1[i]!=num2[i]) return (sign ? num1[i]>num2[i] : num1[i]<num2[i]);
        }
        return false;
    }
    friend bool operator<=(number num1, number num2)
    {
        if (num1._sign && !num2._sign)return true;
        if (!num1._sign && num2._sign)return false;
        bool sign=num1._sign;
        if (num1.size()!=num2.size()) return (sign ? num1.size()>num2.size() : num1.size()<num2.size());
        for (size_t i=num1.size(); i>=0; --i){
            if (num1[i]!=num2[i]) return (sign ? num1[i]>num2[i] : num1[i]<num2[i]);
        }
        return true;
    }
    friend bool operator<(number num1, int num2){
        return num1<number(num2);
    }
    friend bool operator<=(number num1, int num2){
        return num1<=number(num2);
    }


    friend bool operator>(number num1, number num2)
    {
        if (num1._sign && !num2._sign)return false;
        if (!num1._sign && num2._sign)return true;
        bool sign=num1._sign;
        if (num1.size()!=num2.size()) return (sign ? num1.size()<num2.size() : num1.size()>num2.size());
        for (size_t i=num1.size(); i>=0; --i){
            if (num1[i]!=num2[i]) return (sign ? num1[i]<num2[i] : num1[i]>num2[i]);
        }
        return false;
    }
    friend bool operator>=(number num1, number num2)
    {
        if (num1._sign && !num2._sign)return false;
        if (!num1._sign && num2._sign)return true;
        bool sign=num1._sign;
        if (num1.size()!=num2.size()) return (sign ? num1.size()<num2.size() : num1.size()>num2.size());
        for (size_t i=num1.size(); i>=0; --i){
            if (num1[i]!=num2[i]) return (sign ? num1[i]<num2[i] : num1[i]>num2[i]);
        }
        return true;
    }
    friend bool operator>(number num1, int num2){
        return num1>number(num2);
    }
    friend bool operator>=(number num1, int num2){
        return num1>=number(num2);
    }














    friend number operator-(number num1, number num2){
        if (num1.sign()!=num2.sign()){
            // passing to +
            if (num1.sign()){
                num1._sign=!num1._sign;
                return num1+num2;
            }
            else {
                num2._sign=!num2._sign;
                return num1+num2;
            }
        }
        number num3(-100);

        return num3;
    }
    friend number operator+(number num1, number num2){
        if (num1.sign()!=num2.sign()){
            // passing to -
            if (num1.sign()){
                num1._sign=!num1._sign;
                return num1-num2;
            }
            else {
                num2._sign=!num2._sign;
                return num1-num2;
            }
        }
        number num3;
        num3.clear();
        size_t minSize=std::min(num1.size(), num2.size()), i;
        int keep=0;
        for (i=0; i<minSize; ++i){
            keep+=num1[i]+num2[i];
            num3.push_back(keep%10);
            keep/=10;
        }
        while (i<num1.size()){
            keep+=num1[i];
            num3.push_back(keep%10);
            keep/=10;
            ++i;
        }
        while (i<num2.size()){
            keep+=num2[i];
            num3.push_back(keep%10);
            keep/=10;
            ++i;
        }
        while (keep){
            num3.push_back(keep%10);
            keep/=10;
        }
        num3._sign=num1.sign();
        return num3;
    }
    friend std::ostream& operator<<(std::ostream& out, const number& numb){
        if (numb._sign)out<<'-';
        for (int i=numb._numb.size()-1; i>=0; --i){
            out<<numb._numb[i];
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