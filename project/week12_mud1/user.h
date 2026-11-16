class User {
private:
    int hp;

public:
    User(); // 생성자 선언
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    int GetHP();
};