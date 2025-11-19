#pragma once

#include <algorithm>
#include <Array.h>

template<class T>
Array<T>::Array() : current_size(0), current_capacity(1), data(new T[current_capacity], deleteArray) {}

template<class T>
Array<T>::Array(size_t size) : current_size(size), current_capacity(size > 0 ? 4 * size : 1), data(new T[current_capacity], deleteArray) {}

template<class T>
Array<T>::Array(size_t size, const T& value) : current_size(size), current_capacity(size > 0 ? 4 * size : 1), data(new T[current_capacity], deleteArray) {
    for (size_t i = 0; i < current_size; ++i) {
        data[i] = value;
    }
}

template<class T>
Array<T>::Array(const std::initializer_list<T>& list) : current_size(0), current_capacity(1), data(new T[current_capacity], deleteArray) {
    for (const T& element : list) { 
        addElement(element); 
    }
}

template<class T>
Array<T>::Array(const Array& other) : current_size(other.current_size), current_capacity(other.current_capacity), data(new T[current_capacity], deleteArray) {
    std::copy(other.data.get(), other.data.get() + current_size, data.get());
}

template<class T>
Array<T>::Array(Array&& other) noexcept : current_size(other.current_size), current_capacity(other.current_capacity), data(std::move(other.data)) {
    other.current_size = 0;
    other.current_capacity = 0;
}

template<class T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        current_size = other.current_size;
        current_capacity = other.current_capacity;
        data = std::shared_ptr<T[]>(new T[current_capacity], deleteArray);
        std::copy(other.data.get(), other.data.get() + current_size, data.get());
    }
    return *this;
}

template<class T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
    if (this != &other) {
        current_size = other.current_size;
        current_capacity = other.current_capacity;
        data = std::move(other.data);
        
        other.current_size = 0;
        other.current_capacity = 0;
    }
    return *this;
}

template<class T>
void Array<T>::resize(size_t new_capacity) {
    auto new_data = std::shared_ptr<T[]>(new T[new_capacity], deleteArray);
    std::copy(data.get(), data.get() + std::min(current_size, new_capacity), new_data.get());
    data = new_data;
    current_capacity = new_capacity;
    if (current_size > new_capacity) {
        current_size = new_capacity;
    }
}

template<class T>
void Array<T>::addElement(const T& element) {
    if (current_size >= current_capacity) {
        resize(2 * current_capacity);
    }
    data[current_size] = element;
    current_size++;
}

template<class T>
void Array<T>::removeLast() {
    if (current_size) {
        current_size--;
    }
}

template<class T>
void Array<T>::removeAtIndex(size_t index) {
    if (index >= current_size) return;
    for (size_t i = index; i + 1 < current_size; ++i) {
        data[i] = data[i + 1];
    }
    current_size--;
}

template<class T>
void Array<T>::clearAll() { 
    current_size = 0; 
}

template<class T>
T& Array<T>::operator[](size_t index) { 
    return data[index]; 
}

template<class T>
const T& Array<T>::operator[](size_t index) const { 
    return data[index]; 
}

template<class T>
size_t Array<T>::getSize() const { 
    return current_size; 
}

template<class T>
size_t Array<T>::getCapacity() const { 
    return current_capacity; 
}