#include <iostream>
#include "user.h"
using namespace std;

User::User() {
    hp = 20;
    itemCnt = 0;
}

void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
}

void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

void User::IncreaseItem() {
    itemCnt++;
}

int User::GetHP() {
    return hp;
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "현재 HP는 " << user.hp << " 이고, 먹은 아이템은 총 " << user.itemCnt << "개 입니다";
    return os;
}