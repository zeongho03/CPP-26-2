#include <iostream>
#include <windows.h>
using namespace std;

class Circle {
public:
    int radius; //반지름
    string color; //색상

    double CalcArea(){
        return 3.14 * radius * radius;
    }
};

int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Circle pizza1, pizza2;

    pizza1.radius = 100;
    pizza1.color = "yellow";
    cout << "피자의 면적=" << pizza1.CalcArea() << "\n";

    pizza2.radius = 200;
    pizza2.color = "white";
    cout << "피자의 면적=" << pizza2.CalcArea() << "\n";
    return 0;
}