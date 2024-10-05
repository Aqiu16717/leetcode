#pragma once

#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

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

template <typename T1, typename T2>
void printMap(const std::unordered_map<T1, T2>& m) {
    for (auto kv : m) {
        std::cout << "(" << kv.first << "," << kv.second << ")";
    }
    std::cout << std::endl;
}
