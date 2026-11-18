#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include "user.h"
using namespace std;

// 사용자 정의 함수 (displayMap에 두 유저의 좌표를 모두 전달하도록 수정)
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(const vector<vector<int>>& map, int magician_x, int magician_y, int warrior_x, int warrior_y);
bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y);
bool CheckUser(User user);

// 메인 함수
int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	vector<vector<int>> map = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };

    int mapY = map.size();
    int mapX = map[0].size();

	// 각 유저의 위치를 따로 저장할 변수 (둘 다 0, 0에서 시작)
	int magician_x = 0, magician_y = 0;
	int warrior_x = 0, warrior_y = 0;

	// 현재 턴의 유저 좌표를 가리킬 포인터
	int* current_x = nullptr;
	int* current_y = nullptr;

	Magician magician;
	Warrior warrior;
	User* currentUser = nullptr;
	int k = 0;

	// 게임 시작 
	while (1) { 
		switch(k % 2) {
        case 0:
            cout << (k % 2) + 1 << " magician(M)의 차례입니다 -> ";
            currentUser = &magician;
            current_x = &magician_x; // 마법사 좌표 연결
            current_y = &magician_y;
            break;
        case 1:
            cout << (k % 2) + 1 << " warrior(W)의 차례입니다 -> ";
            currentUser = &warrior;
            current_x = &warrior_x;  // 전사 좌표 연결
            current_y = &warrior_y;
            break;
        }

		string user_input = "";
		cout << "명령어를 입력하세요 (상,하,좌,우,지도,종료,정보): ";
		cin >> user_input;

		if (user_input == "상") {
			*current_y -= 1;
			bool inMap = checkXY(*current_x, mapX, *current_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				*current_y += 1;
			}
			else {
				cout << "위로 한 칸 올라갑니다." << endl;
				displayMap(map, magician_x, magician_y, warrior_x, warrior_y);
                currentUser->DecreaseHP(1);
			}
		}
		else if (user_input == "하") {
			*current_y += 1;
			bool inMap = checkXY(*current_x, mapX, *current_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				*current_y -= 1;
			}
			else {
				cout << "아래로 한 칸 내려갑니다." << endl;
				displayMap(map, magician_x, magician_y, warrior_x, warrior_y);
                currentUser->DecreaseHP(1);
			}
		}
		else if (user_input == "좌") {
			*current_x -= 1;
			bool inMap = checkXY(*current_x, mapX, *current_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				*current_x += 1;
			}
			else {
				cout << "왼쪽으로 이동합니다." << endl;
				displayMap(map, magician_x, magician_y, warrior_x, warrior_y);
                currentUser->DecreaseHP(1);
			}
		}
		else if (user_input == "우") {
			*current_x += 1;
			bool inMap = checkXY(*current_x, mapX, *current_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				*current_x -= 1;
			}
			else {
				cout << "오른쪽으로 이동합니다." << endl;
				displayMap(map, magician_x, magician_y, warrior_x, warrior_y);
                currentUser->DecreaseHP(1);
			}
		}
		else if (user_input == "지도") {
			displayMap(map, magician_x, magician_y, warrior_x, warrior_y);
            continue; // 지도 확인 시에는 턴이 넘어가지 않도록 처리
		}
        else if (user_input == "정보") {
            cout << *currentUser << endl;
            continue;
        }
		else if (user_input == "종료") {
			cout << "종료합니다." << endl;
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 둘 중 한 명(현재 이동한 유저)이라도 목적지에 도달했는지 체크
		bool finish = checkGoal(map, *current_x, *current_y);
		if (finish == true) {
			cout << ((k % 2 == 0) ? "Magician" : "Warrior") << "이(가) 목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

        // 무기/갑옷, 포션, 적을 만났을 때 이벤트 처리
        for (int i = 0; i < mapX; i++){
            for (int j = 0; j < mapY; j++){
                // 아이템
                if ((i == *current_x) && (j == *current_y) && (map[j][i] == 1)){
                    cout << "아이템이 있습니다." << endl;
                    currentUser->IncreaseItem();
                }
                // 적
                if ((i == *current_x) && (j == *current_y) && (map[j][i] == 2)){
                    cout << "적이 있습니다. ";
                    currentUser->doAttack();
                    cout << "HP가 2 줄어듭니다." << endl;
                    currentUser->DecreaseHP(2);
                }
                // 포션
                if ((i == *current_x) && (j == *current_y) && (map[j][i] == 3)){
                    cout << "포션이 있습니다. HP가 2 늘어납니다." << endl;
                    currentUser->IncreaseHP(2);
                }
            }
        }

        // HP가 0 이하가 되면 "실패"를 출력하고 종료
        bool alive = CheckUser(*currentUser);
        if (alive == false){
            cout << ((k % 2 == 0) ? "Magician" : "Warrior") << "의 HP가 0 이하가 되었습니다. 실패했습니다." << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }

		k++;
	}
	return 0;
}


// 지도와 두 사용자 위치를 출력하는 함수
void displayMap(const vector<vector<int>>& map, int magician_x, int magician_y, int warrior_x, int warrior_y) {
    int mapY = map.size();
    int mapX = map[0].size();

	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			// M을 먼저 체크하므로 위치가 겹칠 때는 자연스럽게 M이 출력됨
			if (i == magician_y && j == magician_x) {
				cout << "   M  |"; 
			}
			else if (i == warrior_y && j == warrior_x) {
				cout << "   W  |"; 
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y) {
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// 유저의 HP가 0 이하인지 확인하는 함수
bool CheckUser(User user){
    if (user.GetHP() <= 0){
        return false;
    }
    else return true;
}