#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class PrintData { //멤버 함수(메소드) 중복 정의 가능
public:
    void print(int i) {cout << i << endl;}
    void print(double f) {cout << f << endl;}
    void print(string s = "No Data!") {cout << s << endl;}
};

int main() {
    PrintData obj;

    obj.print(1);
    obj.print(3.14);
    obj.print("C++14 is cool. ");
    obj.print();
    return 0;
}