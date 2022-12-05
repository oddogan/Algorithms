#include <iostream>
#include <cassert>

int gTestNum = 1;

template <typename T>
void merge(T *arr, int p, int q, int r) {
    T *L = new T[q-p+1];
    T *R = new T[r-q];

    for (int i = 0; i < (q-p+1); i++) {
        L[i] = arr[p+i];
    }
    for (int i = 0; i < (r-q); i++) {
        R[i] = arr[q+i+1];
    }

    int i = 0;
    int j = 0;
    
    for (int k = p; k < r+1; k++) {
        if (j == (r-q) || (i < (q-p+1) && L[i] <= R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
    }
    
    delete []L;
    delete []R;
}

template <typename T>
void mergeSort(T* arr, int p, int r) {
    if (p < r) {
        int q = (p+r)/2;
        mergeSort(arr, p, q);
        mergeSort(arr, q+1, r);
        merge(arr, p, q, r);
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

    mergeSort(arr, 0, iSize-1);
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