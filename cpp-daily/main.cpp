// =========================================================
// Day2:整数と割り算とstatic_cast
//
// 制作者:h		日付：11/14
// =========================================================
#include <iostream>
#include <vector>

int main()
{
    const int totalDamage = 7;
    const int hitCount = 2;

    std::cout << "7 / 2  = " << totalDamage / hitCount << '\n';
    std::cout << "7 % 2  = " << totalDamage % hitCount << '\n';

    const int negative = -7;
    std::cout << "-7 / 2 = " << negative / hitCount << '\n';
    std::cout << "-7 % 2 = " << negative % hitCount << '\n';
    std::cout << "7 / -2 = " << totalDamage / -hitCount << '\n';
    std::cout << "7 % -2 = " << totalDamage % -hitCount << '\n';

    std::cout << "7 / 2.0 = " << 7 / 2.0 << '\n';

    const double exactRatio = static_cast<double>(totalDamage) / hitCount;
    std::cout << "static_cast<double>(7) / 2 = " << exactRatio << '\n';

    const double wrongRatio = static_cast<double>(totalDamage / hitCount);
    std::cout << "static_cast<double>(7 / 2) = " << wrongRatio << '\n';

    std::cout << "static_cast<int>(3.9)  = " << static_cast<int>(3.9) << '\n';
    std::cout << "static_cast<int>(-3.9) = " << static_cast<int>(-3.9) << '\n';

    const int currentHp = 7;
    const int maxHp = 200;
    const int percentScale = 100;
    std::cout << "bad  percent = " << currentHp / maxHp * percentScale << '\n';
    std::cout << "good percent = " << currentHp * percentScale / maxHp << '\n';

    // =========================================================
    std::cout << "==============\n";
    // =========================================================

    const int totalExp = 2500;
    const int expPerLevel = 400;

    std::cout << "レベル:" << totalExp / expPerLevel << "\n";
    std::cout << "次のレベルまで " << expPerLevel - (totalExp % expPerLevel) << " EXP\n";
    std::cout << "達成率:" << static_cast<double>(totalExp % expPerLevel) / expPerLevel << "\n";

    // =========================================================
    std::cout << "==============\n";
    // =========================================================
    // x が負のとき、タイル番号が本来より1つ大きい側にズレる。
    // 0番のタイルだけ -31～31 の63個分になり、他の32個分より広くなる

    const int tileSize = 32;
    const std::vector<int> positions = { -33, -32, -31, -1, 0, 1, 31, 32, 33 };

    std::cout << "x\ttitle\n";

    for (std::size_t i = 0; i < positions.size(); i++)
    {
        const int position = positions[i];
        const int plainIndex = position / tileSize;

        std::cout << position << '\t' << plainIndex << '\n';
    }

    // =========================================================
    std::cout << "==============\n";
    // =========================================================

    const int itemsPerPage = 10;
    const std::vector<int> sampleCounts = { 0, 1, 9, 10, 11, 20, 23 };

    std::cout << "items\tplain\tceil\n";

    for (std::size_t i = 0; i < sampleCounts.size(); i++)
    {
        const int itemCount = sampleCounts[i];
        const int plainPageCount = itemCount / itemsPerPage;
        const int ceilPageCount = (itemCount + itemsPerPage - 1) / itemsPerPage;

        std::cout << itemCount << '\t' << plainPageCount << '\t' << ceilPageCount << '\n';
    }

    return 0;
}