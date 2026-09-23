#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
    int list[10];
    int max;

    for (int i = 0; i < 10; i++){
        int elem = rand() % 100 + 1;
        list[i] = elem;
        cout << elem << " ";
    }
    cout << endl;
    max = list[0];
    for (auto elem : list) {
        if (elem > max)
            max = elem;
    }
    cout << "최댓값=" << max << endl;
    return 0;
}