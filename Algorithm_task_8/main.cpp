#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
/*
 *Аналогично 1.2, но ломаная должна быть замкнутая. Предполагается, что никакие три точки не лежат на одной прямой.
Указание: стройте ломаную от точки, имеющей наименьшую координату x.
Если таких точек несколько, то используйте точку с наименьшей координатой y.
Точки на ломаной расположите в порядке убывания углов лучей от начальной точки до всех остальных точек.
 9
 1 6
 2 5
 7 10
 2 3
 6 6
 4 7
 3 5
 1 2
 4 3

6
 1 0
 1 2
 0 0
 1 1
 0 2
 2 3

 4
 0 0
 1 1
 1 0
 0 1

 */
using namespace std;

struct Couple {
    int xCoordinate; //  х координата
    int yCoordinate; //  у координата
    double weight;   //  вес точки

    friend bool operator>(const Couple &a, const Couple &b); // перегрузка для сортировки
    friend bool operator<(const Couple &a, const Couple &b);

    friend bool operator==(const Couple &a, const Couple &b);

    Couple() : xCoordinate(0), yCoordinate(0), weight(-1) { }

};

void insertionSort(vector<Couple> &vector1) {

    for (int i = 2; i < vector1.size(); i++) {
        for (int j = i; j > 1 && vector1[j - 1] > vector1[j]; j--) {
            Couple tmp = vector1.at(j - 1);
            vector1[j - 1] = vector1[j];
            vector1.at(j) = tmp;
        }
    }
}

int main() {

    vector<Couple> vector1;

    int n;
    Couple temp;
    int amount = 0;
    cin >> amount;
    for (int i = 0; i < amount; ++i) {
        cin >> n;
        temp.xCoordinate = n;
        cin >> n;
        temp.yCoordinate = n;
        vector1.push_back(temp);
    }

    int minIndex = 0;

    for (int i = 0; i < vector1.size(); ++i) {

        if (vector1[i].xCoordinate == vector1[minIndex].xCoordinate) {
            if (vector1[i].yCoordinate < vector1[minIndex].yCoordinate) {
                minIndex = i;
            }
        }
        if (vector1[i].xCoordinate < vector1[minIndex].xCoordinate) {
            minIndex = i;
        }
    }
    swap(vector1[0], vector1[minIndex]);
    
    int tempY = 0;
    int tempX = 0;
    for (int i = 1; i < vector1.size(); ++i) {
        tempY = vector1[i].yCoordinate - vector1[0].yCoordinate;
        tempX = vector1[i].xCoordinate - vector1[0].xCoordinate;
        if (tempX == 0) {
            vector1[i].weight = 2;
        } else {
            vector1[i].weight = atan2(tempY, tempX);
        }
    }
    insertionSort(vector1);
    for (int j = 0; j < vector1.size(); ++j) {
        cout << vector1[j].xCoordinate << " " << vector1[j].yCoordinate << endl;
    }
    return 0;
}


bool operator>(const Couple &a, const Couple &b) {
    if (a.weight < b.weight) {
        return true;
    } else {
        return false;
    }
}

bool operator<(const Couple &a, const Couple &b) {
    if (a.weight > b.weight) {
        return true;
    } else {
        return false;
    }
}

bool operator==(const Couple &a, const Couple &b) {
    if (a.weight == b.weight) {
        return true;
    } else {
        return false;
    }
}


