#pragma once

#include <Trapezoid.h>

template<class T>
Trapezoid<T>::Trapezoid() : Figure<T>(5) {}

template<class T>
Trapezoid<T>::Trapezoid(const std::initializer_list<Point<T>>& lst) : Figure<T>(lst) {
    if (lst.size() != 4) {
        throw std::invalid_argument("Trapezoid must have 4 points");
    }
}

template<class T>
Trapezoid<T>::~Trapezoid() = default;