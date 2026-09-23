#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
    const int STUDENT = 5;
    const int SUBJECT = 3;
    int scores[STUDENT][SUBJECT];
    string studentsNames[STUDENT] = {"영수", "영희", "철수", "미미", "쥬쥬"};
    string subjectNames[SUBJECT] = {"수학", "영어", "CPP"};

    for (int i = 0; i < STUDENT; i++){
        cout << studentsNames[i]
            << "의 성적을 하나씩 입력하세요." << endl;
        for (int j = 0; j<SUBJECT; j++){
            cout << subjectNames[j] <<":";
            cin >> scores[i][j];
        }
    }

    for (int i = 0; i <STUDENT; i++){
        cout << studentsNames[i] <<"의 평균 점수는 ";
        double sum = 0;
        double average = 0;
        for (int j =0; j <SUBJECT; j++){
            sum += scores[i][j];
        }
        average = sum / SUBJECT;
        cout << average <<"입니다"<<endl;
    }
    return 0;
}