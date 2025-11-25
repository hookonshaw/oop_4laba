#pragma once

#include<initializer_list>
#include<stdexcept>

#include<Figure.h>

template<class T> class Trapezoid : public Figure<T> {
public:
    Trapezoid();
    Trapezoid(const std::initializer_list<Point<T>>&);
    ~Trapezoid();
};

#include<Trapezoid.ipp>