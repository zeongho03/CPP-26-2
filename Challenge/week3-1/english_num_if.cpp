#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int number;
    cout << "숫자를 입력하시오:";
    cin >> number;

    if (number == 0)
        cout << "zero\n";
    else if (number == 1)
        cout << "one\n";
    else
        cout << "many\n";
    
    return 0;
}