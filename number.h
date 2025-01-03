#pragma once
#include <ostream>
#include <vector>
#include <algorithm>


// only works for int type numbers
// new implementation for float type to be added soon as a new class but first will make this one work
class number {
private:
    int _size;
    bool _sign;
    std::vector<short> _numb;

    void setValue(size_t i, int value) {
        _numb[i] = value;
    }
    inline int operator[](size_t i)const { return _numb[i]; }
    bool sign()const { return _sign; }
    int size()const { return _size; }
    void push_back(int value) {
        _numb.push_back(value);
        ++_size;
    }
    void pop_back() {
        _numb.pop_back();
        _size = _numb.size();
        if (!_size) {
            _sign = false;
            ++_size;
            _numb = { 0 };
        }
    }
    inline int back()const {
        return _numb.back();
    }
    void clear() {
        _numb.clear();
        _sign = false;
        _size = 0;
    }
public:
    number() {
        _numb = { 0 };
        _size = 1;
        _sign = false;
    }
    number(std::string numb) {
        _sign = bool(numb[0] == '-');
        if (_sign)numb[0] = '0';
        for (auto it : numb) {
            if (!isdigit(it)) {
                throw("failed to convert nondigit to digit");
                exit(0);
            }
            _numb.push_back(it - '0');
        }
        std::reverse(_numb.begin(), _numb.end());
        while (_numb.back() == 0)_numb.pop_back();
        _size = _numb.size();
        if (!_size) {
            _sign = false;
            _numb = { 0 };
            _size = 1;
        }
    }
    number(int numb) {
        _sign = bool(numb < 0);
        numb = abs(numb);
        do {
            _numb.push_back(numb % 10);
            numb /= 10;
        } while (numb);
        _size = _numb.size();
    }

    // <, >, <= and >= overload, will do afther testing if + works
    friend bool operator<(number num1, number num2)
    {
        if (num1._sign && !num2._sign)return true;
        if (!num1._sign && num2._sign)return false;
        bool sign = num1._sign;
        if (num1.size() != num2.size()) return (sign ? num1.size() > num2.size() : num1.size() < num2.size());
        for (size_t i = num1.size()-1; i >= 0; --i) {
            if (num1[i] != num2[i]) return (sign ? num1[i] > num2[i] : num1[i] < num2[i]);
        }
        return false;
    }
    friend bool operator<=(number num1, number num2)
    {
        if (num1._sign && !num2._sign)return true;
        if (!num1._sign && num2._sign)return false;
        bool sign = num1._sign;
        if (num1.size() != num2.size()) return (sign ? num1.size() > num2.size() : num1.size() < num2.size());
        for (size_t i = num1.size()-1; i >= 0; --i) {
            if (num1[i] != num2[i]) return (sign ? num1[i] > num2[i] : num1[i] < num2[i]);
        }
        return true;
    }
    friend bool operator<(number num1, int num2) {
        return num1 < number(num2);
    }
    friend bool operator<=(number num1, int num2) {
        return num1 <= number(num2);
    }


    friend bool operator>(number num1, number num2)
    {
        if (num1._sign && !num2._sign)return false;
        if (!num1._sign && num2._sign)return true;
        bool sign = num1._sign;
        if (num1.size() != num2.size()) return (sign ? num1.size() < num2.size() : num1.size() > num2.size());
        for (size_t i = num1.size()-1; i >= 0; --i) {
            if (num1[i] != num2[i]) return (sign ? num1[i]<num2[i] : num1[i]>num2[i]);
        }
        return false;
    }
    friend bool operator>=(number num1, number num2)
    {
        if (num1._sign && !num2._sign)return false;
        if (!num1._sign && num2._sign)return true;
        bool sign = num1._sign;
        if (num1.size() != num2.size()) return (sign ? num1.size() < num2.size() : num1.size() > num2.size());
        for (size_t i = num1.size()-1; i >= 0; --i) {
            if (num1[i] != num2[i]) return (sign ? num1[i]<num2[i] : num1[i]>num2[i]);
        }
        return true;
    }
    friend bool operator>(number num1, int num2) {
        return num1 > number(num2);
    }
    friend bool operator>=(number num1, int num2) {
        return num1 >= number(num2);
    }







    std::string to_string() {
        std::string s;
        for (auto it : _numb) {
            s.push_back(char(it + '0'));
        }
        if (_sign)s.push_back('-');
        std::reverse(s.begin(), s.end());
        return s;
    }





    // copy constructors for dumb bullshit
    number(const number& numb) {
        _numb = numb._numb;
        _sign = numb.sign();
        _size = numb.size();
    }
    number(const number& numb, bool sg) {
        _numb = numb._numb;
        _sign = sg;
        _size = numb.size();
    }
    // absolute value
    number av() {
        return number(*this, false);
    }

    // calculus operators
    friend number operator-(number num1, number num2) {
        if (num1.sign() != num2.sign()) {
            // passing to +
            if (num1.sign()) {
                num1._sign = !num1._sign;
                return num1 + num2;
            }
            else {
                num2._sign = !num2._sign;
                return num1 + num2;
            }
        }
        bool swaped = false;
        if (num1.av() < num2.av()) {
            swaped = true;
            std::swap(num1, num2);
        }
        number num3;
        num3.clear();
        size_t i, minSize = std::min(num1.size(), num2.size());
        for (i = 0; i < minSize; ++i) {
            if (num1[i] < num2[i]) {
                num1.setValue(i, num1[i] + 10);
                size_t j = i + 1;
                while (num1[j] == 0 && j < num1.size()) {
                    num1.setValue(j, 9);
                    ++j;
                }
                if (j < num1.size())num1.setValue(j, num1[j] - 1);
            }
            num3.push_back(num1[i] - num2[i]);
        }
        while (i < num1.size()) {
            num3.push_back(num1[i++]);
        }
        num3._sign = (swaped ? !num1.sign() : num1.sign());
        while (num3.back() == 0 && num3.size() > 1) {
            num3.pop_back();
        }
        return num3;
    }
    friend number operator+(number num1, number num2) {
        if (num1.sign() != num2.sign()) {
            // passing to -
            if (num1.sign()) {
                num1._sign = !num1._sign;
                return num1 - num2;
            }
            else {
                num2._sign = !num2._sign;
                return num1 - num2;
            }
        }
        number num3;
        num3.clear();
        size_t minSize = std::min(num1.size(), num2.size()), i;
        int keep = 0;
        for (i = 0; i < minSize; ++i) {
            keep += num1[i] + num2[i];
            num3.push_back(keep % 10);
            keep /= 10;
        }
        while (i < num1.size()) {
            keep += num1[i];
            num3.push_back(keep % 10);
            keep /= 10;
            ++i;
        }
        while (i < num2.size()) {
            keep += num2[i];
            num3.push_back(keep % 10);
            keep /= 10;
            ++i;
        }
        while (keep) {
            num3.push_back(keep % 10);
            keep /= 10;
        }
        num3._sign = num1.sign();
        return num3;
    }


    number(std::vector<short> vec) {
        for (auto it : vec) {
            _numb.push_back(it);
        }
        std::reverse(_numb.begin(), _numb.end());
        _size = _numb.size();
        _sign = false;
    }
    friend bool operator==(number num1, number num2) {
        if (num1.size() != num2.size())return false;
        for (size_t i = 0; i < num1.size(); ++i) {
            if (num1[i] != num2[i])return false;
        }
        return true;
    }
    friend number operator*(number num1, number num2) {
        number num3;
        if (num1 == number(0) || num2 == number(0))return num3;
        std::string zero = "";
        for (auto it_num2 : num2._numb) {
            number numt;
            numt.clear();
            int keep = 0;
            for (auto it_num1 : num1._numb) {
                keep += (it_num1 * it_num2);
                numt.push_back(keep % 10);
                keep /= 10;
            }
            while (keep) {
                numt.push_back(keep % 10);
                keep /= 10;
            }
            num3 = num3 + number(numt.to_string() + zero);
            zero += "0";
        }
        num3._sign = (num1.sign() != num2.sign());
        return num3;
    }

    number operator++() {
        if (_sign == false) {
            size_t i = 0;
            while (i < _size && _numb[i] == 9) {
                _numb[i] = 0;
                ++i;
            }
            if (i < _size) {
                ++_numb[i];
            }
            else {
                _numb.push_back(1);
                ++_size;
            }
        }
        else {
            size_t i = 0;
            while (i < _size && _numb[i] == 0) {
                _numb[i] = 9;
                ++i;
            }
            if (i < _size) {
                --_numb[i];
            }
        }
        return *this;
    }
    // slow /
    // will do later a faster version

    // ok tf is this shit and why is it a better rand function than fucking std::rand ?
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
            std::cout << num1 << " - " << num2 << std::endl;
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