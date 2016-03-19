#include <iostream>


using namespace std;

int fff ( int N) {
    int size  = N + 1;
    int* array = new int[size];
    int mid = 0;
    int sum = 0;
    array[0] = 0;
    array[1] = 0;
    array[2] = 0;
    array[3] = 1;
    array[4] = 1;
    array[5] = 2;
    array[6] = 2;


    if (N % 2 == 0) {
        N = N / 2 - 1;
    } else {
        N = N / 2;
    }

    for (int i = 7; i <= N; ++i) {
        if (i % 2 == 0) {
            mid = i / 2 - 1;
        } else {
            mid = i / 2;
            sum += array[mid];
        }

        array[i] = mid + sum;

    }

    sum = N;
    for (int j = 1; j <= N; ++j) {
        sum += array[j];
    }
    delete [] array;
    return sum;
}


int main() {
   int amount = 0;

    cin >> amount;

    if (amount < 3) {
        cout << 1;
        return 0;
    }
    if (amount == 3 || amount == 4) {
        cout << 2;
        return 0;
    }
    if (amount == 5 || amount == 6) {
        cout << 3;
        return 0;
    }

    cout << fff(amount) + 1;

    return 0;
}


