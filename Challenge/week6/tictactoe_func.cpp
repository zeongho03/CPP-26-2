#include <iostream>
#include <windows.h>
using namespace std;
//3. 좌표의 유효성 체크
bool validation(int x, int y, int numCell, const char board[][3]){
    if (x < 0 || x >= numCell || y < 0 || y >= numCell){
            cout << x << ", " << y << ": ";
            cout << " x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
            return false;
        }
        if (board[x][y] != ' '){
            cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
            return false;
        }
        return true;
}

//5.현재 보드 판 출력
void printBoard(int numCell, const char board[][3]){
    for (int i = 0; i < numCell; i++){
            cout << "---|---|---" << endl;
            for (int j = 0; j < numCell; j++){
                cout << board[i][j];
                if(j == numCell - 1){
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;
}

//6. 모든 칸이 차면 종료
bool Full(int numCell, const char board[][3]){
    int m = 0; //칸을 확인하기 위한 변수
    for (int i = 0; i < numCell; i++){
        for (int j = 0; j < numCell; j++){
            if (board[i][j] != ' '){
                m++;
            }
        }
    }
    return (m == numCell * numCell);
}

//7. 빙고시 승자 출력 후 종료(가로, 세로, 대각선)
bool checkWin(int numCell, const char board[][3], char currentUser, int turn){
    //가로 빙고 시
    for (int i = 0; i < numCell; i++){
        int j = 0;
        if (board[i][j] != ' ' && board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2]){
            cout << "가로에 모두 돌이 놓였습니다!: " << turn%2+1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
            cout << "종료합니다";
            return true;
        }
    }
    //세로 빙고 시
    for (int j = 0; j < numCell; j++){
        int i = 0;
        if (board[i][j] != ' ' && board[i][j] == board[i+1][j] && board[i+1][j] == board[i+2][j]){
            cout << "세로에 모두 돌이 놓였습니다!: " << turn%2+1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
            cout << "종료합니다";
            return true;
        }
    }
    //대각선 빙고 시
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!: " << turn%2+1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
        cout << "종료합니다";
        return true;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!: " << turn%2+1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
        cout << "종료합니다";
        return true;
    }

    return false;
}


int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    const int numCell = 3;
    char board[numCell][numCell]{};
    int x, y; //사용자에게 입력받는 x,y 좌표를 저장할 변수

    //보드판 초기화
    for (x=0; x < numCell; x++) {
        for (y=0; y < numCell; y++){
            board[x][y] = ' ';
        }
    }

    //게임하는 코드
    int k = 0; // 누구 차례인지 체크하기 위한 변수
    char currentUser = 'x'; //현재 유저의 돌을 저장하기 위한 문자 변수
    while(true){
        //1.누구 차례인지 출력
        switch(k % 2) {
        case 0:
            cout << k%2+1 <<"번 유저(x)의 차례입니다 -> ";
            currentUser = 'x';
            break;
        case 1:
            cout << k%2+1 << "번 유저(0)의 차례입니다 -> ";
            currentUser = '0';
            break;
        }

        //2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        //3. 입력받은 좌표의 유효성 체크
        if (!validation(x, y, numCell, board)){
            continue;
        }
        //4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        //5. 현재 보드 판 출력
        printBoard(numCell, board);

        //6. 모든 칸이 차면 종료
        if (Full(numCell, board)){
            cout << "모든 칸이 다 찼습니다. 종료합니다.";
            break;
        }
        //7. 빙고시 승자 출력 후 종료(가로, 세로, 대각선)
        if(checkWin(numCell, board, currentUser, k)){
            break;
        }
        k++;
    }
    return 0;
}