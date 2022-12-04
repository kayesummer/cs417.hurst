// 
//  File:    MemoryBlockMove.cpp
//  Author:  Your Glorious Instructor
//  Purpose:
//  Illustrate the need and design of move constructors and assignment 
//  in C++.   Example is based on material from the Microsoft documentation
//  website at https://docs.microsoft.com/en-us/cpp/cpp/move-constructors-and-move-assignment-operators-cpp?view=msvc-170
//
#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

class MemoryBlock {
private:
    size_t _length;
    int * _data;
public:
    explicit MemoryBlock(size_t myLength) 
        :_length(myLength)
        ,_data(new int[_length]) {
            std::cout << "In MemoryBlock(size_t).length = "
                        << _length << "."
                        << std::endl;
     }

    ~MemoryBlock() {
        std::cout << "MemoryBlock destructor length ="
                    << _length;
        if (_data != nullptr) {
            std::cout <<  " Deleting backing store";
            delete [] _data;
        }
        std::cout << std::endl;
    }

    MemoryBlock(const MemoryBlock & other)
        : _length(other._length),
          _data(new int[other._length])
         {
        std::cout << "In MemoryBlock copy const, length  = "
                << other._length <<". Copying"
                << std::endl;
        std::copy(other._data, other._data + _length, _data);
    }

    MemoryBlock & operator=(const MemoryBlock& rhs) {
        std::cout << "In MemoryBlock copy const, length  = "
            << rhs._length <<". Copying"
            << std::endl;
        if (this != &rhs) {
            delete [] _data;
            _length = rhs._length;
            _data = new int[_length];
            std::copy(rhs._data, rhs._data + _length, _data);
        }
        return *this;
    }
    // Add our own move constructors to the class...
    MemoryBlock(MemoryBlock&& other) noexcept 
        : _data(nullptr), _length(0) {
        std::cout << "In Move constructor, length is = "
                << other._length << std::endl;
            _data = other._data;
            _length = other._length;
            // Now we need to do something to release the data pointer
            // in the source object. Otherwise the destructor would try to
            // free that memory multiple times.
            other._data = nullptr;
            other._length = 0;
    }

    MemoryBlock & operator=(MemoryBlock && rhs) noexcept {
        std::cout << "In Move , length is = "
                << rhs._length << std::endl;
        if (this != &rhs) {
            delete [] _data;
            _data = rhs._data;
            _length = rhs._length;
            // And again we must release the source pointer
            rhs._data = nullptr;
            rhs._length = 0;
        }
        return *this;
    }

    size_t Length() const {
        return _length;
    }
};   

int main() {
    std::vector<MemoryBlock> v;
    v.push_back(MemoryBlock(25));
    v.push_back(MemoryBlock(75));
    v.insert(v.begin() + 1, MemoryBlock(50));
    return 0;
}