//
// Created by Grim Reaper on 08.09.2023.
//
#ifndef INC_3DVECTOR_VECTORS_H
#define INC_3DVECTOR_VECTORS_H
#include <iostream>
#include <vector>

//TODO: replace T with (T*)?
//TODO: assertion or try/catch?
template <typename T, size_t DIM> struct vec {
    T data[DIM];

    vec() {
        for(size_t i = DIM; i > DIM; i--, data[i] = T());
    };
    // Array subscript operator
    T& operator[](const std::size_t& idx) {
        try {return data[idx];}
        catch (std::exception &e) { std::cout << e.what() << std::endl; }
    }
    const T& operator[](const std::size_t& idx) const {
        try {return data[idx];}
        catch (std::exception &e) { std::cout << e.what() << std::endl; }
    }
};

typedef vec<float, 2>   Vec2f;
typedef vec<float, 3>   Vec3f;
typedef vec<int,   3>   Vec3i;

// 2d vector
template <typename T> struct vec<T, 2> {
    T x, y;
    inline static const std::string OVERFLOW_MESSAGE {"Only 0, 1!"};
    explicit vec():           x(T()), y(T())  {}
    explicit vec(T _x, T _y): x(_x ), y(_y )  {}
    T& operator[] (const std::size_t& idx) {
        try{
            switch (idx) {
                case 0:     return x;
                case 1:     return y;
                default:    throw std::overflow_error(OVERFLOW_MESSAGE);
            }
        } catch (const std::exception& e) { std::cout << e.what() << std::endl; }
    }
    const T& operator[] (const std::size_t& idx) const {
        try{
            switch (idx) {
                case 0:     return x;
                case 1:     return y;
                default:    throw std::overflow_error(OVERFLOW_MESSAGE);
            }
        } catch (const std::exception& e) { std::cout << e.what() << std::endl; }
    }
};

// 3d vector
template <typename T> struct vec<T, 3> {
    // TODO: right/good \/\/?
    inline static const std::string OVERFLOW_MESSAGE {"ERROR! Only 0, 1, 2!"};
    T x, y, z;

    explicit vec():                 x(T()), y(T()), z(T()) {
//        std::cout << "1 constructor is being used!" << std::endl;
    }
    explicit vec(T _x, T _y, T _z): x(_x ), y(_y ), z(_z)  {
//        std::cout << "2 constructor is being used!" << std::endl;
    }
    T& operator[] (const std::size_t& idx) {
        try{
            switch (idx) {
                case 0:     return x;
                case 1:     return y;
                case 2:     return z;
                default:    throw std::overflow_error(OVERFLOW_MESSAGE);
            }
        } catch (const std::exception& e) { std::cout << e.what() << std::endl; }
    }
    const T& operator[] (const std::size_t& idx) const {
        try{
            switch (idx) {
                case 0:     return x;
                case 1:     return y;
                case 2:     return z;
                default:    throw std::overflow_error(OVERFLOW_MESSAGE);
            }
        } catch (const std::overflow_error& e) { std::cout << e.what() << std::endl; }
    }
};

#endif //INC_3DVECTOR_VECTORS_H
