#pragma once

#include<initializer_list>
#include<stdexcept>

#include<Figure.h>

template<class T> class Pentagon : public Figure<T> {
public:
    Pentagon();
    Pentagon(const std::initializer_list<Point<T>>&);
    ~Pentagon();
};

#include<Pentagon.ipp>