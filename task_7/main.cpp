#include <iostream>
#include <assert.h>
#include <algorithm>
/*
 * В большой IT­фирме есть только одна переговорная комната. Желающие посовещаться заполняют заявки с желаемым временем начала и конца. Ваша задача определить максимальное количество заявок, которое может быть удовлетворено.
Число заявок ≤ 100000.

Формат входных данных:
Вход содержит только пары целых чисел —  н ачала и концы заявок.
Формат выходных данных:
Выход должен содержать натуральное число —  максимальное число заявок.
 1 2
 2 5
 7 10
 2 3
 6 7
 4 7
 3 6
 3 5
 1 2
 4 5
 -> 5
 */
using namespace std;


struct Couple {
    int start; // время начала
    int finish; //  время конца

    friend bool operator > (const Couple& a,const Couple& b ); // перегрузка для сортировки
    friend bool operator < (const Couple& a,const Couple& b);
    friend bool operator == (const Couple& a,const Couple& b);

    Couple (): start(0), finish(0) {}

};

class Vector { // саморасширяющийся массив структур Couple
public:
    Vector();
    ~Vector();

    void PushBack (int a, int b);

    Couple  PopAtIndex (int i);

    Couple* Begin (); // для сортировки
    Couple* End   ();

    int GetBufferSize () { return bufferSize; }




private:
    Couple* buffer;  // массив из времен начала и конца заседаний
    int     bufferSize; // размер массива
    int     current; // текущее количетсво элементов
    void    grow (); // увеличение размера массива
};

int main() {

    Vector conf;
    int n;
    int i = 1; // для опредения что начало, а что конец
    int temp = 0;
    while (scanf("%d",&n) == 1) { // заполняем вектор входными данными
        switch (i) {
            case 1:
                temp = n;
                break;
            case 2:
                conf.PushBack(temp, n);
                break;
            default:
                break;

            }
        i = (i % 2) + 1;
    }
    sort(conf.Begin(),conf.End()); // сортируем по времени окончания
    int previousCouple = 0; // предыдущия пара
    int result = 1; // конечный результат
    for (int j = 1; j < conf.GetBufferSize() ; ++j) {
        if (conf.PopAtIndex(j).start >= conf.PopAtIndex(previousCouple).finish ) { // находим ближайшее время окончания
            result ++;
            previousCouple = j;
        }
    }
    cout << result;
    return 0;
}


Vector::Vector(): bufferSize(2), current (0) {
    buffer = new Couple[bufferSize]();
}



Vector::~Vector() {
    delete [] buffer;

}


void Vector::PushBack(int a, int b) {
    if (current + 1 > bufferSize  ) {
        grow();
    }
    buffer[current].start = a;
    buffer[current].finish = b;
    current++;
}


Couple Vector::PopAtIndex(int i ) {
    assert(i >= 0 || i < bufferSize);
    return buffer[i];
}


void Vector::grow() {
    int newBufferSize = bufferSize * 2;
    Couple* tempBuffer = new Couple[newBufferSize]();
    for (int i = 0; i < bufferSize; ++i) {
        tempBuffer[i] = buffer[i];

    }
    delete [] buffer;
    buffer = tempBuffer;
    bufferSize = newBufferSize;
}


Couple * Vector::Begin() {
    return buffer;
}


Couple * Vector::End() {
    return buffer + current  ;
}


bool operator > (const Couple& a ,const Couple& b ){
    if (a.finish > b.finish){
        return true;
    } else {
        return false;
    }
}

bool operator < (const Couple& a ,const Couple& b){
    if (a.finish < b.finish){
        return true;
    } else {
        return false;
    }
}

bool operator == (const Couple& a ,const Couple& b){
    if (a.finish == b.finish){
        return true;
    } else {
        return false;
    }
}






