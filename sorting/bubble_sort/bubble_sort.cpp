#include <iostream>
#include <cassert>

int gTestNum = 1;

template <typename T>
void bubbleSort(T *arr, int iSize) {
    bool isAlreadySorted = true;
    int iCnt = 1;
    T tTemp;
    for (int i = 1; i < iSize; i++) {
        for (int j = 0; j < iSize - i; j++) {
            if (arr[j] > arr[j+1]) {
                tTemp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tTemp;
                isAlreadySorted = false;
            }
        }
        if (isAlreadySorted) return;
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

    bubbleSort(arr, iSize);
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