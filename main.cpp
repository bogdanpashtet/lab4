/*  Вариант 9.
    Задание 1. Унарная операция
Создать объект типа очередь. Перегрузить оператор ++ как функцию член и -- как дружественную функцию. (Как
постфиксными так префиксными). ++ добавляет элемент в очередь (пустой элемент, например int i=0),
 -- вытаскивает элемент из очереди. Оператор ! проверяет очередь на пустоту.
    Задание 2. Бинарная операция
Создать класс целых чисел (long). Определить оператор +, как функцию-член и - как дружественную функцию.
    Задание 3.
Создать класс вектор, содержащий ссылку на unsigned long, размерность вектора и переменную ошибки. Класс
имеет конструкторы по умолчанию, конструктор с одним и двумя параметрами, конструктор копирования и
деструктор. Определить оператор +, - , * , - как дружественные функции, =, +=, -=, *=,[] - как функции-члены.
Определить операторы =, +, - , *, +=, -=, *= с типа unsigned long, операторы ++ и --. Определить функцию печати.
Перегрузить операторы вывода и ввода в поток*/

#include "LIFO.h"
#include "long.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

int main() {

    char n;
    char ch = NULL;

    try {
        do {

            cout << "\nEnter number of task (1 or 2) or 3 to exit." << endl;

            cin >> n;
            if (!isdigit(n)) throw invalid_argument("Wrong command.");

            switch (n) {

                case '1': {

                    LIFO queue;
                    do {

                        cout << "\nQ - prefix push;" << endl
                             << "W - postfix push;" << endl
                             << "E - prefix pop;" << endl
                             << "R - postfix pop;" << endl
                             << "T - print queue;" << endl
                             << "Y - is empty?;" << endl
                             << "U - exit;" << endl;

                        cin >> ch;
                        cin.ignore(32767, '\n');      // очищается входной буфер
                        ch = toupper(ch);   // возводит в верхний регистр )
                        switch (ch) {

                            case 'Q':   // перфиксно добавить элемент в очередь
                                ++queue;
                                break;
                            case 'W':   // постфиксно добавить элемент в очередь
                                queue++;
                                break;
                            case 'E':   // префиксно убрать элемент из очереди
                                --queue;
                                break;
                            case 'R':   // постфиксно убрать элемент из очереди
                                queue--;
                                break;
                            case 'T':   // вывести очередь в консоль
                                queue.print();
                                break;
                            case 'Y':   // проверить очередь на пустоту
                                !queue;
                                break;
                            case 'U':
                                break;

                            default:
                                cout << "Wrong command...";
                                break;
                        }
                    } while (ch != 'U');

                    break;
                }

                case '2': {
                    cout << "Enter basic counter value: " << endl;
                    std::string l;
                    cin >> l;
                    cin.ignore(32767, '\n');
                    for (unsigned __int8 j = 0; j < l.length() ; j++) {   // проверяем корректность ввода
                        if (  !((l[j] >= '0') && ( l[j] <= '9')) )      // если не цифра, то вызвать исключение
                            throw invalid_argument("Incorrect value.");
                    }

                    tLong number(stol(l));
                    do {

                        cout << "\nW - summation;" << endl
                             << "E - subtraction" << endl
                             << "U - exit;" << endl;

                        cin >> ch;
                        cin.ignore(32767, '\n');       // очищается входной буфер
                        ch = toupper(ch);   // возводит в верхний регистр )
                        string k;
                        switch (ch) {

                            case 'W': { // функция-член, добавляющая число
                                cout << "Enter number to summation." << endl;
                                cin >> k;
                                cin.ignore(32767, '\n');
                                for (unsigned __int8 j = 0; j < k.length() ; j++) {   // проверяем корректность ввода
                                    if (  !((k[j] >= '0') && ( k[j] <= '9')) )      // если не цифра, то вызвать исключение
                                        throw invalid_argument("Incorrect value.");
                                }
                                number + stol(k);
                                number.print();
                                break;
                            }

                            case 'E': { // дружественная функция, отнимающая число
                                cout << "Enter number to subtraction." << endl;
                                cin >> k;
                                cin.ignore(32767, '\n');
                                for (unsigned __int8 j = 0; j < k.length() ; j++) {   // проверяем корректность ввода
                                    if (  !((k[j] >= '0') && ( k[j] <= '9')) )      // если не цифра, то вызвать исключение
                                        throw invalid_argument("Incorrect value.");
                                }
                                number - stol(k);
                                number.print();
                                break;
                            }

                            case 'U':
                                break;

                            default:
                                cout << "Wrong command...";
                                break;
                        }
                    } while (ch != 'U');

                    break;

                }

                case '3':
                    return 0;

                default:
                    cout << "Wrong task...";
                    break;
            }
            cin.ignore(32767, '\n');

        } while (n != '4');
    }
    catch(invalid_argument &error) {
        cout << "Error: " << error.what() << endl;
    }

    return 0;
}

