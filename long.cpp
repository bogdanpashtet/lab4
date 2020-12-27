//

//
#include<malloc.h>
#include "long.h"

using namespace std;

tLong::tLong(){
    value = (long*)malloc(sizeof(long));
    *value = 0;
}

tLong::tLong(long i){
    value = (long*)malloc(sizeof(long));
    *value = i;
}

tLong &tLong::operator+(int i) {
    *value += i;
    return *this;
}

tLong &operator-(tLong &loong, int i) {
    *loong.value -= i;
    return loong;
}

void tLong::print(){
    cout << "Current value: " << *value << endl;
}

tLong::~tLong() {
    cout << "Element was destroyed. " << endl;
    delete[] this->value;
}


