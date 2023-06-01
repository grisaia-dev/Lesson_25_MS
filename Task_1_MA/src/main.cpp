#include <iostream>
#include <vector>

template<typename Type>
void move_vectors(std::vector<Type>& lhs, std::vector<Type>& rhs) {
    lhs = std::move(rhs);
}
/* Не очень понял какую именно шаблонную функцию сделать поэтому, сделал две */
template<typename Type>
std::vector<Type> move_vectors(std::vector<Type>& rhs) {
    return std::move(rhs);
}

int main(void) {
    std::vector<std::string> one = { "test_string1", "test_string2" };
    std::vector<std::string> two;

    for (const auto& i : one)
        std::cout << i << " ";
    std::cout << "\n";
    move_vectors(two, one);
    for (const auto& i : two)
        std::cout << i << " ";
    std::cout << "\n";

    std::cout << "----------------------" << std::endl;
    one = move_vectors(two);
    for (const auto& i : one)
        std::cout << i << " ";
    std::cout << "\n";

    return 0;
}