// Найти, на сколько нулей оканчивается n! = 1 * 2 * 3 * ... * n. n ≤ 1000.
#include <iostream>

using namespace std;

int calcZeros (int count) { // подсчет нулей в факториале

    int numberOfZeros = count/5;
    numberOfZeros += count / 25;
    numberOfZeros += count / 125;
    numberOfZeros += count / 625;

    return numberOfZeros;
}

int main() {

    int count = 0;
    cin >> count; //исходный число для факториала

    cout << calcZeros(count);

    return 0;
}