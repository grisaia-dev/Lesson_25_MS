#pragma once
//#include <iostream>
#include <ostream>
#include <vector>

class big_integer {
public:
    big_integer() : number(0) {}
    big_integer(std::string value) {
        for (auto& digit : value)
            number.push_back(digit - '0');
        std::reverse(number.begin(), number.end());
    }
    big_integer(std::vector<int> value) : number(value) {}
    big_integer(big_integer&& other) noexcept : number(std::move(other.number)) {} // Конструктор перемещения
    big_integer(long long value) { // Если захотим передавать значение типа int
        while(value) {
            this->number.push_back(value % base);
            value /= base;
        }
    }
    big_integer& operator=(big_integer&& other) noexcept { // Перемещающий оператор присваивания
        std::swap(this->number, other.number);
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const big_integer& value) {
        for (int i=value.number.size()-1; i >= 0; i--)
            out << value.number[i];
        return out;
    }

    friend big_integer operator+(const big_integer& left, const big_integer& right); // сложение
    friend big_integer operator-(const big_integer& left, const big_integer& right); // вычитание
    friend big_integer operator*(const big_integer& left, const big_integer& right); // умножение
    friend big_integer operator/(const big_integer& left, const big_integer& right); // деление

    friend bool operator<=(const big_integer& left, const big_integer& right);
private:
    int base = 10;
    std::vector<int> number;
};