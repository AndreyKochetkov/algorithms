#include <iostream>

using namespace std;

int searchMaxIndexes(int *firstArray, int *secondArray, int sizeOfArray, int &firstMaxIndex, int &secondMaxIndex) {
    if (firstArray == 0 || secondArray == 0 || sizeOfArray < 0) {
        return -1;
    }
    int currentMaxFirstIndex = 0;
    firstMaxIndex = 0;
    secondMaxIndex = 0;
    for (int i = 1; i < sizeOfArray; ++i) {  // идем по первому массиву
        if (firstArray[i] > firstArray[currentMaxFirstIndex]) { // если текущий элемент первого массива больше текущего максмума
            currentMaxFirstIndex = i; // запоминаем
        }
        /*
        if ( secondArray[i] > secondArray[secondMaxIndex] ) { // если текущий элемент второго массива больше текущего максмума
            secondMaxIndex = i; // запоминаем
        }
         */
        if (firstArray[currentMaxFirstIndex] + secondArray[i] > firstArray[firstMaxIndex] + secondArray[secondMaxIndex]) { //если текущий максимум больше ранее найденного
            secondMaxIndex = i; // обновляем
            firstMaxIndex = currentMaxFirstIndex;
        }
    }
    return 0;
}


int main() {

    int n = 0;
    if (scanf("%d", &n) != 1) {
        return 0;
    }
    int *firstArray = new int[n];
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &firstArray[i]) != 1) {
            delete[] firstArray;
            return 0;
        }
    }
    int *secondArray = new int[n];
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &secondArray[i]) != 1) {
            delete[] firstArray;
            delete[] secondArray;
            return 0;
        }
    }
    int firstMaxIndex = 0;
    int secondMaxIndex = 0;
    if (searchMaxIndexes(firstArray, secondArray, n, firstMaxIndex, secondMaxIndex) != 0) {
        delete[] firstArray;
        delete[] secondArray;
        return 0;
    }
    cout << firstMaxIndex << " " << secondMaxIndex;

    delete[] firstArray;
    delete[] secondArray;

    return 0;
}