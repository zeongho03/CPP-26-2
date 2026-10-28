#include <iostream>
using namespace std;

class Time{
private:
    int minute; //0~59
    int hour; //0~23
public:

    Time(int h, int m);
    void IncHour();
    void Print();

    int GetHour() { return hour;}
    int GetMinute() { return minute; }
    void SetHour (int h) { hour = h; }
    void SetMinute(int m) {minute = m;}
};

Time::Time(int h, int m){ //외부작성
    hour = h;
    minute = m;
}
void Time::IncHour(){ //외부작성
    ++hour;
    if(hour > 23)
        hour = 0;
}
void Time::Print(){ //외부작성
    cout << hour << ":" << minute << endl;
}

int main(){
    Time a{ 0, 0};
    //a.hour = 10; // private속성이므로 접근 불가 
    //-> 처음부터 h=10으로 초기화 or hour을 public 속성으로 바꾸기
    a.SetHour(10); //또는 함수 호출
    a.SetHour(6);
    a.SetMinute(30);

    a.Print();
    return 0;
}