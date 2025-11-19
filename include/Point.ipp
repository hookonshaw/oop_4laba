#pragma once

#include <Point.h>

template<class T> 
Point<T>::Point() : coordinate_x(0), coordinate_y(0) {}

template<class T> 
Point<T>::Point(T x_value, T y_value) : coordinate_x(x_value), coordinate_y(y_value) {}

template<class T>
std::istream& operator>>(std::istream& input_stream, Point<T>& point) {
    input_stream >> point.coordinate_x >> point.coordinate_y;
    return input_stream;
}

template<class T>
std::ostream& operator<<(std::ostream& output_stream, const Point<T>& point) {
    output_stream << '(' << point.coordinate_x << ' ' << point.coordinate_y << ')';
    return output_stream;
}

template<class T> 
bool operator==(const Point<T>& first_point, const Point<T>& second_point) { 
    return first_point.coordinate_x == second_point.coordinate_x && first_point.coordinate_y == second_point.coordinate_y; 
}

template<class T> 
bool operator!=(const Point<T>& first_point, const Point<T>& second_point) { 
    return !(first_point == second_point); 
}