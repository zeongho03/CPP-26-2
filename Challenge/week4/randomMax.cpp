#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int numCell = 10;
    int numList[numCell][numCell];

    for (int i = 0; i < numCell; i++){
        for (int j = 0; j < numCell; j++){
            cout << i << ", " << j << " : ";
            cin >> numList[i][j];
        }
    }
    cout << endl;

    int max = 0; //큰값 저장을 위한 변수
    int maxI; // 큰 값이 있는 i
    int maxJ; // 큰 값이 있는 j

    for (int i = 0; i < numCell; i++){
        for (int j = 0; j < numCell; j++){
            if (max < numList[i][j]){
                max = numList[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }
    cout << "가장 큰 값은 " << max << "이고,";
    cout << "i와 j는 각각 " <<maxI << ", "<<maxJ << "입니다." << endl;
    cout << "검증 결과: " << numList[maxI][maxJ] << endl;

    return 0;
}