// =========================================================
// Day3:関数と値渡し
//
// 制作者:h		日付：11/16
// =========================================================
#include <iostream>
#include <cstdlib>

int turnCount = 0;

// 攻撃力と防御力から与えるダメージを計算する
int calculateDamage(int attack, int defense)
{
    int damage = attack - defense;
    if (damage < 1) {
        return 1; // ダメージは最低1
    }
    return damage;
}

// 残りHPを割合（0.0〜1.0）で返す
double calculateHpRatio(int currentHp, int maxHp)
{
    return static_cast<double>(currentHp) / maxHp;
}

// 受け取ったHPから damage を引いた値を返す（呼び出し側のHPは変えない）
int applyDamage(int hp, int damage)
{
    hp = hp - damage;
    if (hp < 0) {
        return 0;
    }
    return hp;  
}

int healPlayer(int hp, int healAmount)
{
    hp = hp + healAmount;
    if (hp > 100)
    {
        return 100;
    }
    return hp;
}

int nextTurn()
{
    turnCount = turnCount + 1;
    return turnCount;
}

int nextTurnLocal()
{
    int localCount = 0;
    localCount = localCount + 1;
    return localCount;
}

int attackTo(int num, int atk, int def)
{
    int damege;
    if (num == 1)
    {
        damege = atk * 2 - def;
        if (damege < 1) damege = 1;
        return damege;
    }
    else
    {
        damege = atk - def;
        if (damege < 1) damege = 1;
        return damege;
    }
}

int eHpAfter(int eHp, int damege)
{
    eHp = eHp - damege;
    if (eHp < 0) eHp = 0;
    return eHp;
}

int main()
{
    int playerHp        = 100;
    int enemyAttack     = 34;
    int playerDefense   = 12;

    int damage = calculateDamage(enemyAttack, playerDefense);
    std::cout << "damage = " << damage << '\n';

    int hpAfter = applyDamage(playerHp, damage);
    std::cout << "returned hp = " << hpAfter << '\n';
    std::cout << "playerHp (caller) = " << playerHp << '\n';

    playerHp = hpAfter;
    std::cout << "hp ratio = " << calculateHpRatio(playerHp, 100) << '\n';

    std::cout << "weak attack damage = " << calculateDamage(5, 99) << '\n';

    // =========================================================
    std::cout << "==========\n";
    // =========================================================

    int hp = 80;
    int healhp = healPlayer(80, 30);
    std::cout << "hp:" << hp << " healhp :" << healhp << "\n";

    // =========================================================
    std::cout << "==========\n";
    // =========================================================

    int first    = nextTurn();
    int second   = nextTurn();
    int third    = nextTurn();
    std::cout << "gloval: " << first << ' ' << second << ' ' << third << "\n";

    int a = nextTurnLocal();
    int b = nextTurnLocal();
    int c = nextTurnLocal();
    std::cout << "local: " << a << ' ' << b << ' ' << c << '\n';

    // =========================================================
    std::cout << "==========\n";
    // =========================================================
    int enemyHp = 100;
    int eMaXHp = 100;
    int playerAttack = 34;
    int enemyDefense = 12;

    for (int i = 0; i < 3; i++)
    {
        int num = rand() % 2;
        int damage2 = attackTo(num, playerAttack, enemyDefense);
        enemyHp = eHpAfter(enemyHp, damage2);
        std::cout << "hp%" << static_cast<double>(enemyHp) / eMaXHp << "\n";
    }

    return 0;
}