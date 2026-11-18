#include <iostream>

class User {
private:
    int hp;
    int itemCnt;
public:
    User();
    void doAttack();
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    void IncreaseItem();
    int GetHP();
    friend std::ostream& operator<<(std::ostream& os, const User& user);
};

class Magician : public User{void doAttack();};
class Warrior : public User{void doAttack();};