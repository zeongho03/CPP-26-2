#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<int> student;
    int count = 0;
    while(true){
        int grade;
        
        cout << "성적을 입력하시오(종료는 -1) : ";
        cin >> grade;

        if(grade == -1) break;
        count++;
        student.push_back(grade);
    }
    int sum = 0;
    for (auto &e : student){
        sum += e;
    }
    cout << "성적 평균=" << sum / count; 
}