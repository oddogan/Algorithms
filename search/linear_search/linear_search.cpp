#include <iostream>
#include <cassert>

template <typename T>
int linearSearch(T* arr, int iSize, T tKey) {
    for (int i = 0; i < iSize; i++) {
        if (arr[i] == tKey) return i;
    }
    return -1;
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
    T* tpArr = new T[iSize];
    T tVal = 0;

    for(int i = 0; i < iSize; i++) {
        tpArr[i] = tVal;
        tVal += 1;
    }

    std::cout << "Array: ";
    printArray(tpArr, iSize);

    for(int i = 0; i < 5; i++) {
        T tKey = std::rand()%(iSize*2);

        std::cout << "Searching " << tKey << " in array...";
        // Check if the elements exists and assert
        assert(linearSearch(tpArr, iSize, tKey) == (tKey<iSize) ? tKey : -1);
        std::cout << "Passed!" << std::endl;
    }
    delete []tpArr;
}

int main() {

    runTest<int>(15);
    runTest<double>(7);
    runTest<float>(5);

    return 0;
}