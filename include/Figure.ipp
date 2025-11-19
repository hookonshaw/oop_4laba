#pragma once

#include <Figure.h>

template<class T> 
Figure<T>::Figure(size_t number_of_points) : points_array(number_of_points) {}

template<class T> 
Figure<T>::Figure(const std::initializer_list<Point<T>>& points_list) : points_array(points_list) {}

template<class T>
long double Figure<T>::calculatePolygonArea(const Array<Point<T>>& polygon_points) const {
    long double area_result{0.0};
    for (int i = 0; i + 1 < polygon_points.getSize(); ++i) {
        area_result += polygon_points[i].coordinate_x * static_cast<long double>(polygon_points[i + 1].coordinate_y);
        area_result -= polygon_points[i + 1].coordinate_x * static_cast<long double>(polygon_points[i].coordinate_y);
    }
    area_result += static_cast<long double>(polygon_points[polygon_points.getSize() - 1].coordinate_x) * static_cast<long double>(polygon_points[0].coordinate_y);
    area_result -= static_cast<long double>(polygon_points[0].coordinate_x) * static_cast<long double>(polygon_points[polygon_points.getSize() - 1].coordinate_y);
    return std::abs(area_result / 2.0);
}

template<class T> 
long double Figure<T>::calculateArea() const {
    return calculatePolygonArea(points_array); 
}

template<class T>
Point<T> Figure<T>::calculatePolygonCenter(const Array<Point<T>>& polygon_points) const {
    T sum_x{0}, sum_y{0};
    for (int i = 0; i < polygon_points.getSize(); ++i) {
        sum_x += polygon_points[i].coordinate_x;
        sum_y += polygon_points[i].coordinate_y;
    }
    return Point<T>(sum_x / static_cast<T>(polygon_points.getSize()), sum_y / static_cast<T>(polygon_points.getSize()));
}

template<class T> 
Point<T> Figure<T>::calculateCenter() const {
    return calculatePolygonCenter(points_array); 
}

template<class T> 
void Figure<T>::printAllPoints(std::ostream& output_stream) const {
    for (size_t i = 0; i < points_array.getSize(); ++i) {
        output_stream << points_array[i];
        if (i + 1 < points_array.getSize()) {
            output_stream << " ";
        }
    }
}

template<class T> 
void Figure<T>::readAllPoints(std::istream& input_stream) {
    for (size_t i = 0; i < points_array.getSize(); ++i) {
        input_stream >> points_array[i].coordinate_x >> points_array[i].coordinate_y;
    }
}

template<class T> 
bool operator==(const Figure<T>& first_figure, const Figure<T>& second_figure) {
    if (first_figure.points_array.getSize() != second_figure.points_array.getSize()) { 
        return false; 
    }
    for (int i = 0; i < first_figure.points_array.getSize(); ++i) {
        if (first_figure.points_array[i] != second_figure.points_array[i]) {
            return false;
        }
    }
    return true;
}

template<class T> 
bool operator!=(const Figure<T>& first_figure, const Figure<T>& second_figure) { 
    return !(first_figure == second_figure); 
}

template<class T> 
std::istream& operator>>(std::istream& input_stream, Figure<T>& figure) {
    figure.readAllPoints(input_stream);
    return input_stream;
}

template<class T> 
std::ostream& operator<<(std::ostream& output_stream, Figure<T>& figure) {
    figure.printAllPoints(output_stream);
    return output_stream;
}