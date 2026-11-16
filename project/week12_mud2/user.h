#include <iostream>

class User {
private:
    int hp;
    int itemCnt;
public:
    User();
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    void IncreaseItem();
    int GetHP();
    int GetItemCnt();
    friend std::ostream& operator<<(std::ostream& os, const User& user);
};