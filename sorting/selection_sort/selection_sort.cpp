#include <iostream>
#include <cassert>

int gTestNum = 1;

template <typename T>
void selectionSort(T *arr, int iSize) {
    int iMin = 0;
    int iInd = 0;
    for (int i = 0; i < iSize-1; i++) {
        iMin = arr[i];
        iInd = i;
        for (int j = i+1; j < iSize; j++) {
            if (iMin > arr[j]) {
                iMin = arr[j];
                iInd = j;
            }
        }
        arr[iInd] = arr[i];
        arr[i] = iMin;
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

    selectionSort(arr, iSize);
    std::cout << "After: ";
    printArray(arr, iSize);

    assert(std::is_sorted(arr, arr+iSize));
    std::cout << "Passed!" << std::endl;
    gTestNum++;

    delete []arr;
}

int main() {
    runTest<int>(10);
    runTest<double>(10);
    runTest<float>(10);
    return 0;
}