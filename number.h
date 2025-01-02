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


    // < and > overload, will do afther testing if + works
    friend bool operator<(number num1, number nbum2)
    {
        return false;
    }
    friend bool operator<(number num1, int num2){
        return num1<number(num2);
    }
    friend bool operator>(number num1, number nbum2)
    {
        return false;
    }
    friend bool operator>(number num1, int num2){
        return num1>number(num2);
    }



    friend number operator+(number num1, number num2){
        number num3;
        num3.clear();
        if (bool(num1<0)!=bool(num2<0)){
            // need the - operator for this shit
            return num3;
        }
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