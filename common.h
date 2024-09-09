#pragma once

#include <iostream>
#include <set>
#include <vector>

template <typename T>
void printVec(const std::vector<T>& vec) {
    std::cout << "[ ";
    for (auto elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

template <typename T>
void print2DVec(const std::vector<std::vector<T>>& vecs) {
    for (auto vec : vecs) {
        std::cout << "[ ";
        for (auto elem : vec) {
            std::cout << elem << " ";
        }
        std::cout << "]" << std::endl;
    }
}

template <typename T>
void printSet(const std::set<T>& s) {
    std::cout << "[ ";
    for (auto elem : s) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}
