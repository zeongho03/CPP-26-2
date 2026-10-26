#include "car.h"
using namespace std;

int main()
{
    Car myCAR;

    myCAR.setSpeed(80);
    cout << "현재 속도는 ";
        cout << myCAR.getSpeed();

    return 0;
}