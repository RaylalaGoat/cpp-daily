// =========================================================
// Day4:配列と std::array
//
// 制作者:h		日付：11/18
// =========================================================
#include <array>
#include <iostream>

const int kEnemyCount = 4;

// 生配列を受け取る関数（
void printRawArraySize(int values[])
{
    std::cout << "  関数の中の sizeof(values) = " << sizeof(values) << '\n';
}

// std::array を値で受け取る関数
void printTotalHp(std::array<int, 4> enemyHpList)
{
    int total = 0;
    for (std::size_t i = 0; i < enemyHpList.size(); ++i) {
        total += enemyHpList[i];
    }
    std::cout << "  合計HP = " << total << '\n';
}

// std::array を値で受け取って書き換える関数（呼び出し元に影響するか確認）
void damageAll(std::array<int, 4> enemyHpList)
{
    for (std::size_t i = 0; i < enemyHpList.size(); ++i) {
        enemyHpList[i] -= 10;
    }
    std::cout << "  関数の中の先頭HP = " << enemyHpList[0] << '\n';
}

int countAliveEnemies(std::array<int, kEnemyCount> enemyHpList)
{
    int aliveCount = 0;
    for (std::size_t i = 0; i < enemyHpList.size(); ++i) {
        // TODO: HPが1以上なら aliveCount を増やす
        if (enemyHpList[i] > 0)
        {
            aliveCount += 1;
        }
    }
    return aliveCount;
}

int findLowestHpIndex(std::array<int, kEnemyCount> enemyHpList)
{
    // TODO: 暫定の最小を決めて、2番目以降と比べていく
    int minHp = enemyHpList[0];
    for (size_t i = 0; i < enemyHpList.size(); ++i)
    {
        if (minHp > enemyHpList[i])
        {
            minHp = enemyHpList[i];
        }
    }

    return minHp;
}

int main()
{
    // --- 生配列 ---
    int rawHpList[kEnemyCount] = { 100, 80, 50, 30 };

    std::cout << "[生配列]\n";
    std::cout << "  sizeof(rawHpList)    = " << sizeof(rawHpList) << '\n';
    std::cout << "  sizeof(rawHpList[0]) = " << sizeof(rawHpList[0]) << '\n';
    std::cout << "  要素数(割り算で計算)  = "
        << sizeof(rawHpList) / sizeof(rawHpList[0]) << '\n';
    printRawArraySize(rawHpList);

    // --- std::array ---
    std::array<int, kEnemyCount> hpList = { 100, 80, 50, 30 };

    std::cout << "[std::array]\n";
    std::cout << "  sizeof(hpList) = " << sizeof(hpList) << '\n';
    std::cout << "  hpList.size()  = " << hpList.size() << '\n';
    std::cout << "  hpList[2]      = " << hpList[2] << '\n';
    printTotalHp(hpList);

    std::cout << "[値渡しの確認]\n";
    damageAll(hpList);
    std::cout << "  呼び出し元の先頭HP = " << hpList[0] << '\n';

    // --- 平均HP（Day 2 の整数の割り算と static_cast の復習） ---
    int total = 0;
    for (std::size_t i = 0; i < hpList.size(); ++i) {
        total += hpList[i];
    }
    const double average =
        static_cast<double>(total) / static_cast<double>(hpList.size());
    std::cout << "[平均]\n";
    std::cout << "  平均HP = " << average << '\n';

    // =========================================================
    std::cout << "=========\n";
    // =========================================================

    std::array<int, 5> itemList = { 2,3,1,4,5 };

    int addItem = 0;
    int maxList = itemList[0];

    for (size_t i = 0; i < itemList.size(); ++i)
    {
        addItem += itemList[i];

        if (maxList < itemList[i])
        {
            maxList = itemList[i];
        }
    }

    std::cout << "合計個数:" << addItem << "\n";
    std::cout << "一番多いアイテム:" << maxList << "\n";

    // =========================================================
    std::cout << "=========\n";
    // =========================================================

    //std::array<int, 4> mpList = { 10, 20, 30, 40 };

    //std::cout << "書き換え前の mpList[0] = " << mpList[0] << '\n';
    //for (int i = 0; i < 5; ++i) {   // わざと1個多い
    //    hpList[i] = 0;
    //}
    //std::cout << "書き換え後の mpList[0] = " << mpList[0] << '\n';

    std::array<int, 0> emptyList = {};
    std::cout << "size()     = " << emptyList.size() << '\n';
    std::cout << "size() - 1 = " << emptyList.size() - 1 << '\n';

    // =========================================================
    std::cout << "=========\n";
    // =========================================================

    std::array<int, kEnemyCount> enemyHpList = { 100, 5, 50, 30 };

    std::cout << "生存数 = " << countAliveEnemies(enemyHpList) << '\n';
    std::cout << "最弱の添字 = " << findLowestHpIndex(enemyHpList) << '\n';

    return 0;
}