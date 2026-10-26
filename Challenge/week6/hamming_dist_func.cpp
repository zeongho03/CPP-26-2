#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
//문자열을 전부 소문자로 바꾸는 함수
string toLowerStr(string str){
    string newStr = str;
    for (char& c : newStr){
        c=tolower(c);
    }
    return newStr;
}
//문자열을 전부 대문자로 바꾸는 함수
string toUpperStr(string str){
    string newStr = str;
    for (char& c : newStr){
        c=toupper(c);
    }
    return newStr;
}
//문자열을 모두 소문자 또는 대문자로 바꾼 후 비교하는 함수
int calcHammingDist(string s1, string s2){
    s1 = toLowerStr(s1);
    s2 = toLowerStr(s2);
    int count = 0;
    for (int i = 0; i < s1.length(); i++) {
        if(s1[i] != s2[i])
            count += 1;
    }
    return count;
}



int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    string s1, s2;
    int count = 0;
    //입력한 두 문자열의 길이가 같을 때까지 입력 반복
    while(1){
        cout << "DNA 1: ";
        cin >> s1;
        cout << "DNA 2: ";
        cin >> s2;

        if (s1.length() != s2.length())
            cout << "오류: 길이가 다름" << endl;
        else{   
            int count = calcHammingDist(s1, s2);
            cout << "해밍 거리는 " << count << endl;
            break;
        }
    }
    return 0;
}