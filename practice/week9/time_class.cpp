#include <iostream>
using namespace std;

class Time {
public:
    int hour; //시를 나타낸다. 0~23
    int minute; //분을 나타낸다. 0~59
    Time(int h=0, int m=0) { //생성자 중복정의 개선 - 디폴트 매개변수 설정
        hour = h;
        minute = m;
    }

    void Print() {
        cout << hour << ":" << minute << endl;
    }
};

int main(){
    Time a;
    Time b (10, 30);
    Time c {10, 40};
    Time d = { 10, 50 };

    a.Print();
    b.Print();
    c.Print();
    d.Print();
    return 0;
}
