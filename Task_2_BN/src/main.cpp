#include <iostream>
#include "lib/big_integer.hpp"

int main(void) {
    auto number1 = big_integer(114575);
    auto number2 = big_integer(78524);

    auto result = number1 + number2;
    auto result2 = number1 * number2;
    auto result3 = number2 * 2;

    std::cout << *result << std::endl;
    result = result * 2;

    std::cout << *result << std::endl;
    std::cout << *result2 << std::endl;
    std::cout << *result3 << std::endl;
    return 0;
}