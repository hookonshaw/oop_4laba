#pragma once

#include<initializer_list>
#include<stdexcept>

#include<Figure.h>

template<class T> class Rhombus : public Figure<T> {
public:
    Rhombus();
    Rhombus(const std::initializer_list<Point<T>>&);
    ~Rhombus();
};

#include<Rhombus.ipp>