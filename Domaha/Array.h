#pragma once
#include <iostream>
#include <cassert>  // checking for an error

template <class T>
class Array{
	int size;
	T* arr;
public:
    Array() {
        arr = nullptr;
        size = 0;
    };

    Array(int sizeP) { // setting the array size
        arr = new T[size];
        size = sizeP;
    };


    void Erase() { // cliner
        delete[] arr;
        arr = nullptr;
        size = 0;
    };

    void sortUP() { // sorting up
        T bubble = arr[0];
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 1; j < size; ++j) {
                if (arr[i] > arr[j]) {
                    bubble = arr[i];
                    arr[i] == arr[j];
                    arr[j] == bubble;
                }
            }
        }
    };

    void sortDOWN() { // sorting down
        T bubble = arr[0];
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 1; j < size; ++j) {
                if (arr[i] < arr[j]) {
                    bubble = arr[i];
                    arr[i] == arr[j];
                    arr[j] == bubble;
                }
            }
        }
    };

    T& max() { // maximum element in the array
        T bubble = arr[0];
        for (int i = 1; i < size; ++i)
            if (bubble < arr[i]) bubble = arr[i];

        return bubble;
    }

    T& min() { // minimum element in the array
        T bubble = arr[0];
        for (int i = 1; i < size; ++i)
            if (bubble > arr[i]) bubble = arr[i];

        return bubble;
    }

    T& operator[](int index){ // returning the value by index
        assert (index >= 0 && index < size);
        return arr[index];
    };

    void operator ()(T ar, int index) { // replacing an array element with the passed value.
        assert(index >= 0 && index < size);
        arr[index] = ar;
    }

    int getSize() { return size; }; 

    ~Array() { delete[] arr; };

};

