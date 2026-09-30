#include <iostream>
using namespace std;

int a = 100, b = 200;

void swap(){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main(){

    cout << "a=" << a << " b=" << b << endl;

    swap(a, b);

    cout << "a=" << a << " b=" << b << endl;
    return 0;
}