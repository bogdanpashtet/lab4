//
//

#ifndef LAB4_LONG_H
#define LAB4_LONG_H

#include<iostream>

class tLong{
private:
    long *value;
public:
    tLong();
    explicit tLong(long i);
    tLong &operator+(int i);
    friend tLong &operator-(tLong &loong, int i);
    void print();
    ~tLong();
};


#endif //LAB4_LONG_H
