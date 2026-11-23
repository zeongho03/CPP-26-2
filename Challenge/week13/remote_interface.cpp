#include <iostream>
#include <windows.h>
using namespace std;

//리모컨 인터페이스 정의
class RemoteControl{
public:
    //순수 가상 함수 정의
    virtual void TurnON() = 0; //켜기
    virtual void TurnOFF() = 0; //끄기
};

//TV클래스 정의
class Television : public RemoteControl {
public:
    void TurnON(){
        cout << "TV를 켭니다" << endl;
    }
    void TurnOFF(){
        cout << "TV를 끕니다" << endl;
    }
};

//냉장고 클래스 정의
class Refrigerator : public RemoteControl {
public:
    void TurnON() {
        cout << "냉장고를 켭니다" << endl;
    }
    void TurnOFF(){
        cout << "냉장고를 끕니다" << endl;
    }
};

int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    //TV를 켜고 끄는 동작을 인터페이스를 통해 수행
    RemoteControl* remoteTV = new Television();
    remoteTV->TurnON();
    remoteTV->TurnOFF();

    //냉장고를 켜고 끄는 동작을 인터페이스를 통해 수행
    RemoteControl* remoteRefrigerator = new Refrigerator();
    remoteRefrigerator->TurnON();
    remoteRefrigerator->TurnOFF();

    delete remoteTV, remoteRefrigerator;
    return 0;
}