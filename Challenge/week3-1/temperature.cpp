#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int F;
    cout << "화씨온도: ";
    cin >> F;
    double C = (5.0 / 9.0) * (F - 32);
    cout << "섭씨온도 = " + to_string(C);
}