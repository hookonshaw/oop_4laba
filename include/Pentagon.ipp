#pragma once

#include <Pentagon.h>

template<class T>
Pentagon<T>::Pentagon() : Figure<T>(5) {}

template<class T>
Pentagon<T>::Pentagon(const std::initializer_list<Point<T>>& lst) : Figure<T>(lst) {
    if (lst.size() != 5) {
        throw std::invalid_argument("Pentagon must have 5 points");
    }
}

template<class T>
Pentagon<T>::~Pentagon() = default;