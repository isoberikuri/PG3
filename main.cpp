#include <stdio.h>

// 再帰関数：給料が固定給を超えるまで処理を繰り返す
int Recursive(int kyuuryou, int zikan, int koteikyu) {
    if (kyuuryou >= koteikyu) {
        printf("%d時間後に超える\n", zikan);
        return zikan;
    }

    printf("給料: %d　固定給: %d\n", kyuuryou, koteikyu);

    // 給料と固定給を更新
    kyuuryou = kyuuryou * 2 - 50;
    koteikyu += 1226;

    return Recursive(kyuuryou, ++zikan, koteikyu);
}

int main() {
    int saiki = 100;  // 初期給料
    int ippan = 1226; // 初期固定給
    int zikan = 0;    // 開始時の時間（0時間）

    int result = Recursive(saiki, zikan, ippan);

    return 0;
}