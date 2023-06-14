#include "big_integer.hpp"

big_integer operator+(const big_integer& left, const big_integer& right) { // Сложение
    std::vector<int> result;
    int carry = 0;
    for (int i=0; i < std::min(left.number.size(), right.number.size()); i++) {
        int cur_sum = carry + left.number[i] + right.number[i];
        result.push_back(cur_sum % 10);
        carry = cur_sum / 10;
    }

    for (int i = std::min(left.number.size(), right.number.size()); i < std::max(left.number.size(), right.number.size()); i++) {
        if (left.number.size() > right.number.size()) {
            int cur_sum = carry + left.number[i];
            result.push_back(cur_sum % 10);
            carry = cur_sum / 10;
        } else {
            int cur_sum = carry + right.number[i];
            result.push_back(cur_sum % 10);
            carry = cur_sum / 10;
        }
    }
    if (carry != 0)
        result.push_back(carry);
    return big_integer(result);
}

big_integer operator-(const big_integer& left, const big_integer& right) { // Вычитание
    std::vector<int> result;
    int carry = 0;
    for (int i=0; i < right.number.size(); i++) {
        int cur_diff = left.number[i] - right.number[i] - carry;
        if (cur_diff < 0) {
            cur_diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result.push_back(cur_diff);
    }
    for (int i=right.number.size(); i < left.number.size(); i++) {
        if ((left.number[i] - carry) < 0) {
            result.push_back(left.number[i] + 10 - carry);
            carry = 1;
        } else {
            result.push_back(left.number[i] - carry);
            carry = 0;
        }
    }
    while(!result.back() && result.size() > 1) {
        result.pop_back();
    }
    return big_integer(result);
}

big_integer operator*(const big_integer& left, const big_integer& right) { // Умножение
    std::vector<int> result(left.number.size() * right.number.size(), 0);
    for (int i=0; i < left.number.size(); i++) {
        int carry = 0;
        for (int j=0; j < right.number.size(); j++) {
            int cur = result[i + j] + left.number[i] * right.number[j] + carry;
            carry = cur / left.base;
            result[i + j] = cur % left.base;
        }
        int cur = right.number.size();
        while (carry) {
            result[i + cur] = carry % left.base;
            cur++;
            carry /= left.base;
        }
    }
    while(!result.back() && result.size() > 1) {
        result.pop_back();
    }
    return big_integer(result);
}
/* Целочисленное деление */
big_integer operator/(const big_integer& left, const big_integer& right) { // Деление
    std::vector<int> result(left.number.size() - right.number.size() + 1, 0);
    big_integer resultReturn(result);
    for (int i=result.size()-1; i >= 0; i--) {
        while (right * resultReturn <= left) {
            resultReturn.number[i]++;
        }
        resultReturn.number[i]--;
    }
    while(!resultReturn.number.back() && resultReturn.number.size() > 1) {
        resultReturn.number.pop_back();
    }
    return resultReturn;
}

bool operator<=(const big_integer& left, const big_integer& right) {
    if (left.number.size() < right.number.size())
        return true;
    else if (left.number.size() > right.number.size())
        return false;
    else {
        for (int i=left.number.size() - 1; i >= 0; i--) {
            if (left.number[i] > right.number[i])
                return false;
            if (left.number[i] < right.number[i])
                return true;
        }
        return true;
    }
}