#include <iostream>
#include "lib/big_integer.hpp"

int main(void) {
    auto number1 = big_integer("64591348763126459153756459152435628");
    auto number2 = big_integer(5643269487); // Можно использовать и числа типа int
    auto number3 = number1 + number2;
    auto number4 = number1 - number2;
    auto number5 = number1 * number2;
    auto number6 = number1 / number2;

    std::cout << "[Sum]: " << number3 << std::endl;
    std::cout << "[Diff]: " << number4 << std::endl;
    std::cout << "[Mult]: " << number5 << std::endl;
    std::cout << "[Sub]: " << number6 << std::endl;
    return 0;
}