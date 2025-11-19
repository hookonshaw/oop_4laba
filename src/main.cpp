#include<iostream>
#include<memory>

#include<Array.h>
#include<Figure.h>
#include<Pentagon.h>
#include<Rhombus.h>
#include<Trapezoid.h>

int main() {
    std::cout << "INPUT VECTOR SIZE ";
    int vector_size;
    std::cin >> vector_size;
    std::cin.ignore();
    
    Array<std::shared_ptr<Figure<double>>> figures_array;
    
    std::cout << "P-Pentagon\nR-Rhombus\nT-Trapezoid" << std::endl;
    
    for (int i = 0; i < vector_size; ++i) {
        char figure_type;
        std::cin >> figure_type;
        std::cin.ignore();
        
        std::shared_ptr<Figure<double>> current_figure;
        
        if (figure_type == 'P' || figure_type == 'p') {
            current_figure = std::make_shared<Pentagon<double>>();
        } else if (figure_type == 'R' || figure_type == 'r') {
            current_figure = std::make_shared<Rhombus<double>>();
        } else if (figure_type == 'T' || figure_type == 't') {
            current_figure = std::make_shared<Trapezoid<double>>();
        } else {
            std::cout << "ERROR: Invalid figure type" << std::endl;
            break;
        }
        
        std::cin >> *current_figure;
        figures_array.addElement(current_figure);
    }
    
    long double total_area{0.0};
    for (int i = 0; i < figures_array.getSize(); ++i) {
        auto current_figure = figures_array[i];
        total_area += current_figure->calculateArea();
        std::cout << current_figure->calculateCenter() << ' ';
    }
    
    std::cout << std::endl;
    std::cout << "Total area of all figures: " << total_area << std::endl;
    
    return 0;
}