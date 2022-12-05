#include <iostream>
#include <cassert>

int gTestNum = 1;

template <typename T>
void insertionSort(T *arr, int iSize) {
    // The first element is already sorted
    for (int i = 1; i < iSize; i++) {
        T tTemp = arr[i];
        int j = i-1;
        while (j >= 0 && tTemp < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = tTemp;
    }
}

template <typename T>
void randomArrayGenerator(T* arr, int iSize) {
    while (iSize--) {
        arr[iSize] = (T) (std::rand()%2000-1000)/10.0f;
    }
}

template <typename T>
void printArray(T* arr, int iSize) {
    for (int i = 0; i < iSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void runTest(int iSize) {
    T *arr = new T[iSize];

    std::cout << "Test " << gTestNum << ".....\n";

    randomArrayGenerator(arr, iSize);
    std::cout << "Before: ";
    printArray(arr, iSize);

    insertionSort(arr, iSize);
    std::cout << "After: ";
    printArray(arr, iSize);

    assert(std::is_sorted(arr, arr+iSize));
    std::cout << "Passed!" << std::endl;
    gTestNum++;

    delete []arr;
}

int main() {
    runTest<int>(5);
    runTest<double>(5);
    runTest<float>(5);
    return 0;
}