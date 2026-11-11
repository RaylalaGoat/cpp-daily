// =========================================================
// Day1:型とsizeof
//
// 制作者:h		日付：2026/11/11
// =========================================================

#include <cstdint>
#include <iostream>
#include <limits>
#include <iomanip>

int main() {
    // =====================================================
    // 型が何バイト使うか確認
    // =====================================================
    std::cout << "=1= sizeof\n";

    std::cout << "bool          : " << sizeof(bool) << " byte\n";
    std::cout << "char          : " << sizeof(char) << " byte\n";
    std::cout << "short         : " << sizeof(short) << " byte\n";
    std::cout << "int           : " << sizeof(int) << " byte\n";
    std::cout << "long          : " << sizeof(long) << " byte\n";
    std::cout << "long long     : " << sizeof(long long) << " byte\n";
    std::cout << "float         : " << sizeof(float) << " byte\n";
    std::cout << "double        : " << sizeof(double) << " byte\n";
    std::cout << "unsigned int  : " << sizeof(unsigned int) << " byte\n";
    std::cout << "unsigned char : " << sizeof(unsigned char) << " byte\n";

    // long double のサイズは処理系で変わる
    std::cout << "long double   : " << sizeof(long double) << " byte\n";

    // サイズを規格で固定した整数型。セーブデータや通信で使う
    std::cout << "int32_t       : " << sizeof(std::int32_t) << " byte\n";

    // sizeof は型名ではなく変数に適用すると、型を変えても自動で追従する
    const float playerSpeed = 4.5f;
    std::cout << "playerSpeed   : " << sizeof(playerSpeed) << " byte\n";

    // =====================================================
    // 各型が表せる範囲を確認する
    // =====================================================
    std::cout << "\n=2= numeric_limits\n";

    std::cout << "int min : " << std::numeric_limits<int>::min() << '\n';
    std::cout << "int max : " << std::numeric_limits<int>::max() << '\n';
    std::cout << "unsigned int min : " << std::numeric_limits<unsigned int>::min() << '\n';
    std::cout << "unsigned int max : " << std::numeric_limits<unsigned int>::max() << '\n';

    // =====================================================
    // 符号なし整数は 0 を下回ると最大値側から回り込む
    // =====================================================
    std::cout << "\n=3= unsigned wraparound\n";

    const unsigned int unsignedHitPoint = 100;
    const int signedHitPoint = 100;
    const int damage = 150;

    std::cout << "unsigned 100 - 150 : " << (unsignedHitPoint - damage) << '\n';
    std::cout << "signed   100 - 150 : " << (signedHitPoint - damage) << '\n';

    // =====================================================
    // float は値が大きくなると、足した分が丸めで消える
    // =====================================================
    std::cout << "\n=4= float absorption\n";

    std::cout << std::setprecision(10) << std::boolalpha;

    // 10 進の 0.1 や 0.2 は 2 進数で正確に表せないので、足した結果もずれる
    std::cout << "0.1 + 0.2 == 0.3 (double) : " << (0.1 + 0.2 == 0.3) << '\n';

    const float frameTime = 0.016f;

    const float time1 = 1.0f;
    const float time2 = 10000.0f;
    const float time3 = 100000.0f;
    const float time4 = 200000.0f;
    const float time5 = 500000.0f;
    const float time6 = 1000000.0f;

    std::cout << "1.0f       : " << (time1 + frameTime)
        << "  changed? " << (time1 + frameTime != time1) << '\n';
    std::cout << "10000.0f   : " << (time2 + frameTime)
        << "  changed? " << (time2 + frameTime != time2) << '\n';
    std::cout << "100000.0f  : " << (time3 + frameTime)
        << "  changed? " << (time3 + frameTime != time3) << '\n';
    std::cout << "200000.0f  : " << (time4 + frameTime)
        << "  changed? " << (time4 + frameTime != time4) << '\n';
    std::cout << "500000.0f  : " << (time5 + frameTime)
        << "  changed? " << (time5 + frameTime != time5) << '\n';
    std::cout << "1000000.0f : " << (time6 + frameTime)
        << "  changed? " << (time6 + frameTime != time6) << '\n';

    // =====================================================
    // マジックナンバーを名前付き定数にする
    // =====================================================
    std::cout << "\n=5= named constants\n";

    const std::int32_t maxHitPoint = 100;
    const std::int32_t baseDamage = 30;
    const float damageRate = 0.5f;

    const float dealtDamage = baseDamage * damageRate;
    const float remainingHitPoint = maxHitPoint - dealtDamage;
    std::cout << "remainingHitPoint : " << remainingHitPoint << '\n';

    return 0;
}