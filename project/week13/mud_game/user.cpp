#include <iostream>
#include "user.h"
using namespace std;

User::User()
{
    hp = 20;
    itemCnt = 0;
}

Magician::Magician() {};
Warrior::Warrior() {};

void User::DecreaseHP(int dec_hp)
{
    hp -= dec_hp;
}

void User::IncreaseHP(int inc_hp)
{
    hp += inc_hp;
}

void User::IncreaseItem()
{
    itemCnt++;
}

int User::GetHP()
{
    return hp;
}

void User::doAttack()
{
    cout << "공격합니다" << endl;
}

std::ostream &operator<<(std::ostream &os, const User &user)
{
    os << "현재 HP는 " << user.hp << " 이고, 먹은 아이템은 총 " << user.itemCnt << "개 입니다";
    return os;
}

// 마법사 공격 재정의
void Magician::doAttack() {
    cout << "마법 사용" << endl;
}

// 전사 공격 재정의
void Warrior::doAttack() {
    cout << "베기 사용" << endl;
}