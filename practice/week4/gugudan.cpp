#include <iostream>
#include <windows.h>

using namespace std;

#define WIDTH 9
#define HEIGHT 3

int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
    int table[HEIGHT][WIDTH];
    int r, c;

    for (r=0; r < HEIGHT; r++)
        for (c = 0; c < WIDTH; c++)
            table[r][c] = (r + 1)*(c+1);
    
    for (r = 0; r < HEIGHT; r++){
        for (c = 0; c < WIDTH; c++) {
            cout << table[r][c] << ", ";
        }
        cout << endl;
    }
}