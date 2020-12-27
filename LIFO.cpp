//
// Created by  on 24.10.2020.
//

#include "LIFO.h"


//Конструктор
LIFO::LIFO() {
    queue = new int[SIZE];
    head = tail = 0 ;
}

//Вывод элементов очереди
void LIFO::print() {
    for(int i= head + 1; i < tail + 1; i++)
        cout << " " << queue[i];
}

//Определение размера очереди
int LIFO::size() const{
    int s=0;
    for(int i=head; i < tail; i++)
        s++;
    return s;
}

//Помещение элемента в очередь

// prefix push
LIFO &LIFO::operator++(){
    if (tail + 1 == head || (tail + 1 == SIZE && !head )) {
        cout << "Full queue" <<endl ;
        return *this;
    }
    this->tail++;
    if (tail == SIZE )
        this->tail = 0 ;
    queue [tail] = 0;

    return *this;
}

// postfix push
LIFO &LIFO::operator++(int) {
    if (tail + 1 == head || (tail + 1 == SIZE && !head )) {
        cout << "Full queue" << endl;
        return *this;
    }
    tail++;
    if (tail == SIZE )
        tail = 0 ;
    queue [tail] = 0;

    return *this;
}

// Извлечение элемента из очереди

// prefix friendly pop
LIFO &operator--(LIFO &line) {
    if (line.head == line.tail ) {
        cout << "Empty queue" <<endl ;
        return line;
    }
    (line.head)++;
    if (line.SIZE == line.head) line.head = 0 ;

    return line;
}

// postfix friendly pop
LIFO &operator--(LIFO &line, int) {
    if (line.head == line.tail ) {
        cout << "Empty queue" <<endl ;
        return line;
    }
    (line.head)++;
    if (line.head == line.SIZE ) line.head = 0 ;

    return line;
}

LIFO &LIFO::operator!(){
    if (size() == NULL)
        cout << "Empty line." << endl;
    else
        cout << "Queue continue " << size() << " elements." << endl;
    return *this;
}

LIFO::~LIFO() {
    delete [] queue;
    cout  << "\nElement was destroyed." << endl;
}