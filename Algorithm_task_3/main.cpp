#include <iostream>
#include <assert.h>
#include <math.h>

#define DEBUG_1
/*
Дан отсортированный массив различных целых чисел A[0..n­1] и массив целых чисел B[0..m­1].
 Для каждого элемента массива B[i] найдите минимальный индекс элемента массива A[k],
 ближайшего по значению к B[i].
 Время работы поиска для каждого элемента B[i]: O(log(k)).
n ≤ 110000, m ≤ 1000.
3
10 20 30
3
9 15 35

002
3
10 20 30
4
8 9 10 32

0002


 10
15 32 37 41 45 56 64 65 72 93
10
53 7 97 80 21 10 75 46 62 52


 5 0 9 8 0 0 8 4 6 5
 */

using namespace std;


int SearchOfTwin(int key, int *array, int size); // функция бинарного поиска близнеца

void findIntervalOfDegreeOfTwo(int key, int *array, int &left, int &right, int size); // определение интервала галопом (по степеням двойки)

int main() {
    int sizeOfFirstArray = 0;
    int sizeOfSecondArray = 0;
    if (scanf("%d", &sizeOfFirstArray) != 1) {
        return 0;
    }
    int *firstArray = new int[sizeOfFirstArray];
    for (int i = 0; i < sizeOfFirstArray; ++i) {
        if (scanf("%d", &firstArray[i]) != 1) {
            delete[] firstArray;
            return 0;
        }
    }
    if (scanf("%d", &sizeOfSecondArray) != 1) {
        delete[] firstArray;
        return 0;
    }
    int *secondArray = new int[sizeOfSecondArray];
    for (int i = 0; i < sizeOfSecondArray; ++i) {
        if (scanf("%d", &secondArray[i]) != 1) {
            delete[] firstArray;
            delete[] secondArray;
            return 0;
        }
    }
    for (int i = 0; i < sizeOfSecondArray; ++i) {
        cout << SearchOfTwin(secondArray[i], firstArray, sizeOfFirstArray) << " ";
    }

    return 0;
}


int SearchOfTwin(int key, int *array, int size) {
    assert(size >= 0 || array != NULL);
    int left = 0;
    int right = 1;
    int mid = 0;

    if (key <= array[left]) { // если элемент слева
        return left;
    }
    if (key >= array[size - 1]) { // если элемент справа
        return size - 1;
    }
    findIntervalOfDegreeOfTwo(key, array, left, right, size);

    while (right - left > 1) { // пока они не будут рядом, т.е. left - right = 1
        mid = (right + left) / 2;
        if (key < array[mid]) {
            right = mid;
        } else {
            left = mid;
        }
    }
    if (abs(array[left] - key) <= abs(array[right] - key)) { // сравниваем кто ближе к элементу
        return left;
    } else {
        return right;
    }

}

void findIntervalOfDegreeOfTwo(int key, int *array, int &left, int &right, int size) {

    while (right < size && key > array[right]) { // сначала размер, чтобы не запросить невыделенный элемент
        left = right;
        right *= 2;
    }
    if (right > size - 1) { // если перескочили size
        right = size - 1;
    }
}