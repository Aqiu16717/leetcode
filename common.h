#pragma once

#include <iostream>
#include <vector>
#include <set>

template<typename T>
void printVec(const std::vector<T>& vec) {
    std::cout << "[ ";
    for (auto elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

template<typename T>
void printSet(const std::set<T>& s) {
    std::cout << "[ ";
    for (auto elem : s) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}
