#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int money; 
    cout << "현재 가지고 있는 돈: " << endl;
    cin >> money;//현재 가지고 있는 돈 입력
    int candy;
    cout << "캔디의 가격 : " << endl;
    cin >> candy; //캔디 가격 입력
    int max = money / candy; //구입 가능한 캔디 최대 개수
    cout << "최대로 살 수 있는 캔디 = " + to_string(max) << endl;
    int rest = money % candy; // 최대 구입후 남는 돈
    cout << "캔디 구입 후 남은 돈 = " + to_string(rest) << endl;
}