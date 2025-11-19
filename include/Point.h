#pragma once

#include <iostream>

template<class T> class Point;

template<class T> 
std::istream& operator>>(std::istream& input_stream, Point<T>& point);

template<class T> 
std::ostream& operator<<(std::ostream& output_stream, const Point<T>& point);

template<class T> 
bool operator==(const Point<T>& first_point, const Point<T>& second_point);

template<class T> 
bool operator!=(const Point<T>& first_point, const Point<T>& second_point);

template<class T> 
class Point {
public:
    T coordinate_x;
    T coordinate_y;

    Point();
    Point(T x_value, T y_value);
    
    friend std::istream& operator>> <>(std::istream& input_stream, Point<T>& point);
    friend std::ostream& operator<< <>(std::ostream& output_stream, const Point<T>& point);
    friend bool operator== <>(const Point<T>& first_point, const Point<T>& second_point);
    friend bool operator!= <>(const Point<T>& first_point, const Point<T>& second_point);
};

#include <Point.ipp>