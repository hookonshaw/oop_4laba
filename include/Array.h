#pragma once

#include <initializer_list>
#include <memory>

template<class T> 
class Array {
private:
    size_t current_size;
    size_t current_capacity;
    std::shared_ptr<T[]> data;

    static void deleteArray(T* pointer) { 
        delete[] pointer; 
    }

public:
    Array();
    Array(size_t size);
    Array(size_t size, const T& value);
    Array(const std::initializer_list<T>& list);
    Array(const Array& other);
    Array(Array&& other) noexcept;
    ~Array() = default;

    void resize(size_t new_capacity);
    void addElement(const T& element);
    void removeLast();
    void removeAtIndex(size_t index);
    void clearAll();
    
    size_t getSize() const;
    size_t getCapacity() const;
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;
};

#include <Array.ipp>