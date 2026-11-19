// =========================================================
// Day5:enum class
//
// 制作者:h		日付：11/19
// =========================================================
#include <array>
#include <cstdint>
#include <iostream>

// =========================================================
// 1
// =========================================================

enum class SceneId : std::uint8_t
{
    Title,
    Stage,
    Result,
    GameOver,
};

void printSceneName(SceneId scene)
{
    switch (scene)
    {
    case SceneId::Title:    std::cout << "Title";    break;
    case SceneId::Stage:    std::cout << "Stage";    break;
    case SceneId::Result:   std::cout << "Result";   break;
    case SceneId::GameOver: std::cout << "GameOver"; break;
    }
    std::cout << '\n';
}

// =========================================================
// 2
// =========================================================

// 下地型あり（uint8_t：0〜255 を表現できる）
enum class A : std::uint8_t { X = 0, Y = 1 };

// 下地型なし（列挙子は 0 と 1 だけ）
enum B { BX = 0, BY = 1 };

// =========================================================
// 3
// =========================================================

enum class DamageType : std::uint8_t
{
    Slash,
    Pierce,
    Fire,
    Ice,
    Count,  // 属性の数。実際の属性ではない
};

const std::size_t damageTypeCount = static_cast<std::size_t>(DamageType::Count);

// 属性ごとの耐性値（DamageType の並び順と一致させる）
const std::array<int, damageTypeCount> resistanceTable =
{
    10,  // Slash
    5,   // Pierce
    0,   // Fire
    50,  // Ice
};

std::size_t toIndex(DamageType type)
{
    return static_cast<std::size_t>(type);
}

int calculateFinalDamage(int baseDamage, DamageType type)
{
    const int damage = baseDamage - resistanceTable[toIndex(type)];
    if (damage < 0)
    {
        return 0;
    }
    return damage;
}

void printDamageTypeName(DamageType type)
{
    switch (type)
    {
    case DamageType::Slash:  std::cout << "Slash";  break;
    case DamageType::Pierce: std::cout << "Pierce"; break;
    case DamageType::Fire:   std::cout << "Fire";   break;
    case DamageType::Ice:    std::cout << "Ice";    break;
        // Count は番兵なので表示しない。
        // default にせず case で書くことで、属性を追加したときの書き忘れをコンパイラが警告できる。
    case DamageType::Count:  break;
    }
}

int main()
{
    std::cout << static_cast<int>(SceneId::Title) << '\n';
    std::cout << static_cast<int>(SceneId::Stage) << '\n';
    std::cout << static_cast<int>(SceneId::Result) << '\n';
    std::cout << static_cast<int>(SceneId::GameOver) << '\n';

    printSceneName(SceneId::Title);
    printSceneName(SceneId::Stage);
    printSceneName(SceneId::Result);
    printSceneName(SceneId::GameOver);

    // =========================================================
    std::cout << "======\n";
    // =========================================================

    const int outOfRangeValue = 300;

    // 定義済み動作：300 はまず uint8_t へ変換され 44 になる（256 を超えた分が切り捨てられる）。
    // 列挙子にない値だが、結果は規格で決まっている。
    const A fixedEnum = static_cast<A>(outOfRangeValue);

    // 未定義動作：B は下地型を書いていないので、
    // 列挙子 0〜1 を表すのに必要な範囲を超える値へのキャストは規格が結果を決めていない。
    // 300 と表示されても「この環境ではたまたまそうなった」だけ。
    const B unfixedEnum = static_cast<B>(outOfRangeValue);

    std::cout << "A : " << static_cast<int>(fixedEnum) << '\n';
    std::cout << "B : " << static_cast<int>(unfixedEnum) << '\n';
    std::cout << "sizeof(A) = " << sizeof(A) << '\n';
    std::cout << "sizeof(B) = " << sizeof(B) << '\n';

    // =========================================================
    std::cout << "======\n";
    // =========================================================

    const int baseDamage = 30;

    for (std::size_t i = 0; i < damageTypeCount; ++i)
    {
        const DamageType type = static_cast<DamageType>(i);
        printDamageTypeName(type);
        std::cout << " : " << calculateFinalDamage(baseDamage, type) << '\n';
    }

    return 0;
}