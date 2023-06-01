#pragma once
#include <iostream>

class big_integer {
private:
    long int* value;
public:
    big_integer(long int number) : value(new long int(number)) {}
    big_integer(big_integer&& other) noexcept : value(std::move(other.value)) {} // Конструктор перемещения

    big_integer& operator=(big_integer&& other) noexcept { // Перемещающий оператор присваивания
        std::swap(value, other.value);
        return *this;
    }

    big_integer operator+(const big_integer& other) { return *value + *other.value; } // оператор сложения двух больших чисел
    big_integer operator+(long int other) { return *value + other; }
    big_integer operator*(long int other) { return *value * other; } // оператор умножения на число
    big_integer operator*(const big_integer& other) { return *value * *other.value; }

    long int& operator*() { return *value; }

    ~big_integer() { delete this->value; }
    };