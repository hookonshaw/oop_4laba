#pragma once

#include<iostream>
#include <sstream>
#include<initializer_list>
#include<cmath>

#include "Array.h"
#include "Point.h"

template<class T> class Figure;

template<class T> 
bool operator==(const Figure<T>& first_figure, const Figure<T>& second_figure);

template<class T> 
bool operator!=(const Figure<T>& first_figure, const Figure<T>& second_figure);

template<class T> 
std::istream& operator>>(std::istream& input_stream, Figure<T>& figure);

template<class T> 
std::ostream& operator<<(std::ostream& output_stream, Figure<T>& figure);

template<class T> 
class Figure {
public:    
    virtual ~Figure() = default;
    long double calculateArea() const;
    Point<T> calculateCenter() const;
    
    Figure(size_t number_of_points);
    Figure(const std::initializer_list<Point<T>>& points_list);

    friend bool operator== <>(const Figure<T>& first_figure, const Figure<T>& second_figure);
    friend bool operator!= <>(const Figure<T>& first_figure, const Figure<T>& second_figure);
    friend std::istream& operator>> <>(std::istream& input_stream, Figure<T>& figure);
    friend std::ostream& operator<< <>(std::ostream& output_stream, Figure<T>& figure);

    void readAllPoints(std::istream& input_stream);
    void printAllPoints(std::ostream& output_stream) const;

protected:
    Array<Point<T>> points_array;
    long double calculatePolygonArea(const Array<Point<T>>& polygon_points) const;
    Point<T> calculatePolygonCenter(const Array<Point<T>>& polygon_points) const;
};

#include<Figure.ipp>