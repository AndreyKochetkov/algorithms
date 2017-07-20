#include <iostream>
#include <string.h>
#include <assert.h>
/*
  Дано выражение в инфиксной записи. Вычислить его, используя перевод выражения в постфиксную запись.
  Выражение не содержит отрицительных чисел.
Количество операций ≤ 100.
Формат входных данных. Строка, состоящая их символов “0123456789­+* /()”
Гарантируется, что входное выражение корректно, нет деления на 0, вычислимо в целых числах.
 Деление целочисленное.
Формат выходных данных.
Значение выражения.
 1+2
 3
(8+2*5)/(1+3*2-4)
 6
200-(123+34*2)+(48-2)
55
 */
using namespace std;


int getPriority(char operand) { // получение приоритета операнда
    if (operand == '*' || operand == '/') {
        return 4;
    }
    if (operand == '+' || operand == '-') {
        return 3;
    }
    if (operand == '(') {
        return 2;
    }
    if (operand == ')') {
        return 1;
    }
    return -1;
}


int calculate(string outStr);


class Stack {
public:
    Stack();

    ~Stack();

    void Push(int a); //обычный пуш
    int Pop();  // не извлекает эллемент из стека
    int Top();  // извлекает
    bool IsEmpty() const { return top == -1; }

private:
    int *buffer;
    int bufferSize;
    int top;

    void grow(); //увеличение размерности массива при заполнении
};

int main() {
    char symbol = '0'; //текущий элемент
    string outStr;      // выходная строка в постфиксной нотации
    bool isPreviousSymbolNumber = false; // является ли пред символ числом
    Stack stackForCalculate; // стек для перевода
    while (scanf("%c", &symbol) == 1) {
        if (symbol == '\n' || symbol == '\0') {
            break;
        }
        if (isdigit(symbol) != 0) {
            isPreviousSymbolNumber = true; //ставим флаги
            outStr.push_back(symbol); //заносим в выходную строку все числа
        } else {
            //if ( symbol == '(' || '+' || '-' || '*' || '/' || ')' )
            if (isPreviousSymbolNumber) {
                outStr.push_back(' '); //заносим пробелы после чисел
                isPreviousSymbolNumber = false; // меняем флаги
            }
            if (symbol == '(' || symbol == ')') {
                if (symbol == '(') {
                    stackForCalculate.Push(symbol); // ( всегда в стек
                } else {
                    while (stackForCalculate.Pop() != '(') {
                        outStr.push_back(char(stackForCalculate.Top())); //извлекаем пока не найдем (
                    }
                    stackForCalculate.Top();
                }
            } else {
                if (stackForCalculate.IsEmpty()) {
                    stackForCalculate.Push(symbol); //если пуст просто кладем операнд
                } else {

                    while (!stackForCalculate.IsEmpty()) { // иначе
                        if (getPriority(char(stackForCalculate.Pop())) >= getPriority(symbol)) {
                            outStr.push_back(char(stackForCalculate.Top())); // если операнд ниже или равен приоритетом
                        } else {
                            break; //если выше
                        }
                    }
                    stackForCalculate.Push(symbol); //все равно кладем в стек
                }
            }
        }
    }
    while (!stackForCalculate.IsEmpty()) {
        outStr.push_back(char(stackForCalculate.Top())); //заносим оставшиеся операторы в строку
    }
    cout << calculate(outStr); //считаем результат




    return 0;
}


Stack::Stack() : bufferSize(2), top(-1) {
    buffer = new int[bufferSize];
}


Stack::~Stack() {
    delete[] buffer;
}


void Stack::Push(int a) {
    if (top + 2 > bufferSize) {
        grow();
    }
    //assert(top + 1 <  bufferSize);
    buffer[++top] = a;
}


int Stack::Pop() {
    assert(top != -1);
    return buffer[top];
}


int Stack::Top() {
    assert(top != -1);
    return buffer[top--];
}


void Stack::grow() {
    int newBufferSize = bufferSize * 2;
    int *tempBuffer = new int[newBufferSize];
    for (int i = 0; i < bufferSize; ++i) {
        tempBuffer[i] = buffer[i];
    }
    delete[] buffer;
    buffer = tempBuffer;
    bufferSize = newBufferSize;
}


int calculate(string outStr) {
    Stack stack;
    bool isNumberFirst = true;
    int tempInt = 0;
    int first = 0;
    int second = 0;
    for (int i = 0; i < outStr.length(); ++i) {
        if (isdigit(outStr[i])) {
            if (isNumberFirst) {
                stack.Push(outStr[i] % 48); // из-за таблицы
                isNumberFirst = false;
            } else {
                tempInt = stack.Top();
                stack.Push(tempInt * 10 + outStr[i] % 48);
            }
        }
        if (outStr[i] == ' ') { //по пробелу определяем что число закончилось
            isNumberFirst = true;
        }
        if (outStr[i] == '+') {

            first = stack.Top();
            second = stack.Top();
            stack.Push(first + second);
        }
        if (outStr[i] == '-') {
            first = stack.Top();
            second = stack.Top();
            stack.Push(second - first);
        }
        if (outStr[i] == '/') {
            first = stack.Top();
            second = stack.Top();
            stack.Push(second / first);
        }
        if (outStr[i] == '*') {
            first = stack.Top();
            second = stack.Top();
            stack.Push(first * second);
        }
    }
    return stack.Top();
}



