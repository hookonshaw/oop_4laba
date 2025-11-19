#pragma once

#include <Rhombus.h>

template<class T>
Rhombus<T>::Rhombus() : Figure<T>(5) {}

template<class T>
Rhombus<T>::Rhombus(const std::initializer_list<Point<T>>& lst) : Figure<T>(lst) {
    if (lst.size() != 4) {
        throw std::invalid_argument("Pentagon must have 5 points");
    }
}

template<class T>
Rhombus<T>::~Rhombus() = default;