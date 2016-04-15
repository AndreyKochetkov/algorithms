#include <iostream>
#include <algorithm>
/*
Дан массив неотрицательных целых 64­разрядных чисел. Количество чисел не больше 10 .
Отсортировать массив методом поразрядной сортировки LSD по байтам.

 3
4 1000000 7
4 7 1000000

10
544
4344 2344 644 844 144 9044 344
244 644

 1 2 3 5 6 7 8 23 43 90


 3
544 644 144

 544 = 1000100000   32
 644 = 1010001000   132


 236 = 11101100
 547 = 1000100011
 0 байт = 35
 1 байт = 2 (512)
 */
using namespace std;

int toByte(long long a, int i) {
    return int((a >> (8 * i)) & 255);
}
template<class T>
void quickSortR(T* a, long N) {
// На входе - массив a[], a[N] - его последний элемент.

    long i = 0, j = N-1; 		// поставить указатели на исходные места
    T temp, p;

    p = a[ N / 2 ];		// центральный элемент

    // процедура разделения
    do {
        while ( a[i] < p ) i++;
        while ( a[j] > p ) j--;

        if (i <= j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++; j--;
        }
    } while ( i<=j );


    // рекурсивные вызовы, если есть, что сортировать
    if ( j > 0 ) quickSortR(a, j);
    if ( N > i ) quickSortR(a+i, N-i);
}
/*
void f (int* count, int range, long long* aux, int size, long long *data, int j) {
    for (int i = 1; i < range; ++i) {
        count[i] = 0;
    }
    for (int i = 0; i < size; ++i) {
        ++count[toByte(data[i], j) + 1];
    }
    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }
}


void count_sort(long long *data, int size) {
    int range = 255;
    int *count = new int[range];
    long long *aux = new long long[size + 1];

    for (int j = 0; j < 8; ++j) {
        f(count, range, aux, size, data, j);
        for (int i = 0; i < size; ++i) {
            aux[count[toByte(data[i], j)]] = data[i];
        }
        for (int i = 0; i < size; i++) {
            data[i] = aux[i];
        }

    }

    delete[] aux;
    delete[] count;
}
*/
struct Couple {
    long long value; // время начала
    int byte; //  время конца

    friend bool operator>(const Couple &a, const Couple &b); // перегрузка для сортировки
    friend bool operator<(const Couple &a, const Couple &b);

    friend bool operator==(const Couple &a, const Couple &b);

    Couple() : value(0), byte(0) { }

};

void quick_sort(Couple *a, int n) {
    int i = 0;
    int j = n - 1;
    bool side = 0;
    while (i != j) {
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            side = !side;
        }
        if (side) {
            ++i;
        } else {
            --j;
        }
    }
    if (i > 1) quick_sort(a, i);
    if (n > i + 1) quick_sort(a + (i + 1), n - (i + 1));
}

void LSDSort(long long *data, int size) {

}

int main() {
    int n = 0;
    cin >> n;
    /*
    long long *array = new long long[n];
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
     */
    //count_sort(array, n);
    Couple *array = new Couple[n];
    for (int k = 0; k < n; ++k) {
        cin >> array[k].value;
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < n; ++j) {
            array[j].byte = toByte(array[j].value, i);
        }
        //quick_sort(array, n);
        sort(array, &array[n]);
        //quickSortR(array, n);
    }
    for (int j = 0; j < n; ++j) {
        cout << array[j].value << " ";
    }
    delete[] array;
    return 0;
}


bool operator>(const Couple &a, const Couple &b) {
    if (a.byte > b.byte) {
        return true;
    } else {
        return false;
    }
}

bool operator<(const Couple &a, const Couple &b) {
    if (a.byte < b.byte) {
        return true;
    } else {
        return false;
    }
}

bool operator==(const Couple &a, const Couple &b) {
    if (a.byte == b.byte) {
        return true;
    } else {
        return false;
    }
}

