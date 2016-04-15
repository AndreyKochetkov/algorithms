#include <iostream>

//template<class T>
void sort(BlackInt *begin, BlackInt *end);

template<class T>
T *choosePivot(T *begin, T *end);

template<class T>
T *partition(T *begin, T *end);

template<class T>
void insertionSort(T *, unsigned long);

/*
int main() {

    long long size;
    size = 1000000;

    long *array = new long[size];
    for (long long i = 0; i < size; ++i) {
        array[i] = rand();
    }

    sort(array, array + size - 1);
    for (long long j = 0; j < size; j = j + 100) {
        std::cout << array[j] << " ";
    }
    delete[] array;
    return 0;
};
*/

//template<class T>
void sort(BlackInt *begin, BlackInt *end) {
    while (end - begin > 0) {
        if (end - begin < 50) {
            insertionSort(begin, end - begin);
            break;
        }
        BlackInt *middle = partition(begin, end);
        if ((middle - begin) > (end - middle)) {
            sort(middle + 1, end);
            end = middle - 1;
        } else {
            sort(begin, middle - 1);
            begin = middle + 1;
        }


    }

}

template<class T>
void insertionSort(T *array, unsigned long size) {
    unsigned long j = 0;
    for (unsigned long i = 1; i < size; ++i) {
        T tmp = array[i];
        for (j = i; j > 0 && tmp < array[j - 1]; --j) {
            array[j] = array[j - 1];
        }
        array[j] = tmp;
    }
}

template<class T>
T *choosePivot(T *begin, T *end) {

    T *middle = (begin + (end - begin) / 2);;

    if (*begin > *end) {
        std::swap(*begin, *end);
    }
    if (*middle < *begin) {
        std::swap(*middle, *begin);
    }
    if (*middle > *end) {
        std::swap(*middle, *end);
    }
    return middle;
    // попробывать из 5ти

}

template<class T>
T *partition(T *begin, T *end) {
    T *pivot = choosePivot(begin, end);
    T *currentLeft = begin + 1;
    T *currentRight = end;
    while (true) {
        while (*pivot > *currentLeft && end - currentLeft >= 0) {
            currentLeft++;
        }
        while (*pivot < *currentRight) {
            currentRight--;
            currentLeft++;
        }
        if (currentLeft - currentRight >= 0) {
            std::swap(*begin, *(currentLeft - 1));
            return currentLeft - 1;
        }
        std::swap(*currentLeft, *currentRight);
        ++currentLeft;
        --currentRight;
    }
}