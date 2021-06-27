#include <iostream>
#include <ctime>
#include "Array.h"

int main()
{
    srand(time(nullptr));
    Array <int> arr(20);
    Array <char> arr2(20);

    for (int i = 0; i < arr.getSize(); ++i) {
        arr[i] = rand() % 10;
        arr2[i] = rand() % 6;
    }

    for (int i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << "  " << arr2[i] << std::endl;
    }
}

