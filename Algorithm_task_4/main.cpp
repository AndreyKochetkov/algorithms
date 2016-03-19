#include <iostream>

//#define DEBUG_1
//Реализовать очередь с динамическим зацикленным буфером.
using namespace std;

class Queue {
public:
    Queue ();
    ~Queue () { delete [] buffer;}

    void Enqueue (int a);
    int Dequeue ();

private:
    int* buffer;
    int  bufferSize;
    int  head;
    int  tail;

    void Grow ();
};


int main() {
    int n = 0;
    if ( scanf("%d", &n) != 1) {
        cout << "NO";
#ifdef DEBUG_1
        cout << "ошибка ввода размерности" << endl;
#endif
        return 0;
    }
    Queue* firstQueue = new Queue();
    int value = 0; // для хранения значения
    int command = 0;// для хранения команды
    for (int j = 0; j < n * 2; ++j) {
        if ( scanf("%d", &value) != 1) { // считывание символа
#ifdef DEBUG_1
            cout << "ошибка ввода первого массива" << endl;
#endif
            cout << "NO";
            delete  firstQueue;
            return 0;
        }
        if (j % 2 == 0) { // если команда
            if (value == 2 || value == 3){ // если команда валидна
                command = value;
            } else { //если не валидна
                cout << "NO";
                delete  firstQueue;
                return 0;
            }
        } else { // если значение
            if (command == 3) { // добавляем в очередь
                firstQueue->Enqueue(value);
            } else { // удаляем
                if (firstQueue->Dequeue() != value) {
                    cout << "NO";
                    delete  firstQueue;
                    return 0;
                }
            }
        }
    }
    cout << "YES";
    delete firstQueue;
    return 0;
}


Queue::Queue(): bufferSize(2), head (0), tail (0) {
    buffer = new int[bufferSize];
}


void Queue::Enqueue(int a) {

    if ((tail + 1) % bufferSize == head ){ //увеличение размерности в 2 раза
        Grow();
    }
    //assert( (tail + 1) % bufferSize != head);
    buffer[tail++] = a;
    if (tail == bufferSize) {
        tail = 0;
    }
}


int Queue::Dequeue() {

    //assert(head != tail);
    if (head == tail) {
        return -1;
    }
    int result = buffer[head++];
    if (head == bufferSize) {
        head = 0;
    }
    return result;
}


void Queue::Grow() {
    int newBufferSize =  bufferSize * 2;
    int* tempBuffer = new int[newBufferSize];
    if (tail < head) { //если был захлест. Т.е. все случаи кроме того, когда head == 0, tail == bufferSize
        for (int i = 0, j= head; i < bufferSize - head; ++i, ++j) { // идем по искомому массиву с head до size и заносим в начало нового массива с 0 до size - head
            tempBuffer[i] = buffer [j];
        }
        for (int j = bufferSize - head, i = 0; j < bufferSize ; ++j, ++i) { // идем по искомому с 0 до tail, а по второму с size - head до конца
            tempBuffer[j] = buffer [i];
        }
        tail = bufferSize -1; // переопределяем хвост и голову
        head = 0;
    } else {
        for (int j = 0; j < bufferSize; ++j) { // самый простой случай
            tempBuffer[j] = buffer [j];
        }

    }
    delete [] buffer;
    buffer = tempBuffer; // новый массив и размер
    bufferSize = newBufferSize;
}


