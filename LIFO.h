//

//

#ifndef LAB4_LIFO_H
#define LAB4_LIFO_H


#include <iostream>
using namespace std;

class LIFO {
private:
    static const int SIZE=100;
    int *queue;
    int head, tail;
public :
    LIFO () ;   // конструктор
    void print();   // печать элементов очереди
    int size() const;   // размер очереди
    LIFO &operator++(); // prefix push
    LIFO &operator++(int); // postfix push
    friend LIFO &operator--(LIFO &line);    // prefix friendly pop
    friend LIFO &operator--(LIFO &line, int);   // postfix friendly pop
    LIFO &operator!();  // проверка на пустоту
    ~LIFO();
} ;

#endif //LAB4_LIFO_H
