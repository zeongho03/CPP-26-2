#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    string name;
    cout << "이름을 입력하시오: ";
    cin >> name;
    cout << name << "을 환영합니다." << endl;
    return 0;
}