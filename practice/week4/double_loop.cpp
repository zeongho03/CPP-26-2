#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    cout << "구구단 출력:" << endl;

    for (int i = 2; i <= 9; ++i){
        cout << i << "단:" << endl;

        for (int j = 1; j <= 9; ++j) {
            cout << 1 << " x " << j << " = " << (i * j) << endl;
        }

        cout << endl;
    }
    return 0;
}