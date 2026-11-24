#include <iostream>

class User
{
private:
    int hp;
    int itemCnt;

public:
    User();
    virtual ~User() = default;

    virtual void doAttack() = 0;
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    void IncreaseItem();
    int GetHP();
    friend std::ostream &operator<<(std::ostream &os, const User &user);
};

class Magician : public User
{
public:
    Magician();
    void doAttack();
};
class Warrior : public User
{
public:
    Warrior();
    void doAttack();
};