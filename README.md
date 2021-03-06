# algorithms

---

### basic algorithms

* abstract structures

* sorts

* hash functons

* trees

### implementation: C/C++

### Tasks

### 1. ​нули

Найти, на сколько нулей оканчивается n! = 1 * 2 * 3 * ... * n.

n ≤ 1000.

in out

25 6


### 2. первая пара индексов

​Даны два массива целых чисел одинаковой длины A[0..n­1] и B[0..n­1]. 

Необходимо найти первую пару индексов i0 и j0, i0 ≤ j0, 

такую что A[i0] + B[j0] = max {A[i] + B[j], 

где 0 <= i < n, 0 <= j < n, i <= j}. 

Время работы ­ O(n).

n ≤ 100000.


### 3. минимальный индекс

Дан отсортированный массив различных целых чисел A[0..n­1] и массив целых чисел B[0..m­1].

Для каждого элемента массива B[i] найдите минимальный индекс элемента массива A[k],
ближайшего по значению к B[i].

Время работы поиска для каждого элемента B[i]: O(log(k)).

n ≤ 110000, m ≤ 1000.

in 3

out 10 20 30

in 3

out 9 15 35

### 4. очередь с динамическим зацикленным буфером.

Формат входных данных.

В первой строке количество команд n. n ≤ 1000000.

Каждая команда задаётся как 2 целых числа: a b.

a = 1 ­ push front

a = 2 ­ pop front

a = 3 ­ push back

a = 4 ­ pop back

Для очереди используются команды 2 и 3. Для дека используются все четыре команды.

Если дана команда pop*, то число b ­ ожидаемое значение.Если команда pop вызвана для пустой структуры

данных, то ожидается “­1”.

Формат выходных данных.

Требуется напечатать YES ­ если все ожидаемые значения совпали. Иначе, если хотя бы одно ожидание не

оправдалось, то напечатать NO.

### 5. постфиксная запись

Дано выражение в инфиксной записи. 

Вычислить его, используя перевод выражения в постфиксную запись.

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

### 6. пирамида

Дано N кубиков. Требуется определить каким количеством способов можно выстроить из этих кубиков

пирамиду.

Формат входных данных:

На вход подается количество кубиков N.

Формат выходных данных:

Вывести число различных пирамид из N кубиков.

​Каждый вышележащий слой пирамиды должен быть не больше нижележащего.

N ≤ 200.

### 7. переговорная комната

В большой IT­фирме есть только одна переговорная комната. Желающие посовещаться заполняют заявки с

желаемым временем начала и конца. Ваша задача определить максимальное количество заявок, которое

может быть удовлетворено.

Число заявок ≤ 100000.

Формат входных данных:

Вход содержит только пары целых чисел — начала и концы заявок.

Формат выходных данных:

Выход должен содержать натуральное число — максимальное число заявок.

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

### 8. Ломаная

Задано N точек на плоскости. 

Указать (N­1)­звенную несамопересекающуюся  ломаную,

проходящую через все эти точки. 8. 

Ломаная должна быть замкнутая. 


Предполагается, что никакие три точки не лежат на одной прямой.

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

### 10. LSD

Дан массив неотрицательных целых 64­разрядных чисел.
 
Количество чисел не больше 10 .

Отсортировать массив методом поразрядной сортировки LSD по байтам.


3

4 1000000 7

4 7 1000000


10

544

4344 2344 644 844 144 9044 344

244 644

### 11. "быстрейшая" сортировка

Дан массив данных типа BlackIntразмером N < 10^10.

Требуется упорядочить его по возрастанию с использованием попарных сравнений элементов.

Решение должно содержать реализацию функции voidsort(BlackInt*begin,BlackInt*end);

Разрешается использовать операции сравнения: < > <= >= == !=, операции присвоения между элементами типа BlackInt:

BlackInt a = b;

std::swap(begin[0], begin[1]);

begin[0].swap(begin[1]);


За основу  взят алгоритм быстрой сортировки.

Набор оптимизаций:

1. Оптимизация выбора опорного элемента.

2. Оптимизация Partition.

3. Оптимизация концевой рекурсии.

4. Написать без рекурсии.
