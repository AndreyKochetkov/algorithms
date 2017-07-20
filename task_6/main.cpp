#include <iostream>
#include <inttypes.h>


using namespace std;


int64_t calcNumberOfPyramids (int64_t** table, int64_t n, int64_t minLevel) { // minlevel - минимальное количество кубиков на верхнем уровне, n - общее количество на уровне
    int64_t numberOfPyramids = 0;

    if (n == 0 || n == minLevel) { // если n == minlevel, то 1 вариант. Если n == 0, то он сам
        return 1;
    }
    if (minLevel > n) {
        return 0;
    }
    if (table[n][minLevel] > -1) {
        return table[n][minLevel];
    }
    for (int64_t i = minLevel; i <= n ; ++i) {
        numberOfPyramids += calcNumberOfPyramids(table, n - i, i + 1);
    }
    table [n][minLevel] = numberOfPyramids;
    return numberOfPyramids;

}


int main() {
    int amount = 0;
    if (scanf("%d", &amount) != 1) {
        return 0;
    }
    int64_t** table = new int64_t* [amount + 1];
    for (int i = 0; i < amount + 1; ++i) {
        table[i] = new int64_t[amount + 1];
        for (int j = 0; j < amount + 1; ++j) {
            table[i][j] = -1;
        }
    }

    cout << calcNumberOfPyramids(table, amount, 1);
    for (int k = 0; k < amount + 1; ++k) {
        delete [] table[k];
    }
    delete table;


    return 0;
}


