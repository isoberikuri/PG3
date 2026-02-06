#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// 使用例
//void PrintHelloWorld(void) { printf("HelloWorld\n"); }
//int main(void) {
//  // 関数ポインタを宣言
//  void (*pfunc)();
//
//  pfunc = PrintHelloWorld;
//  printf("PrintHelloWorld7 FL = %p\n", PrintHelloWorld);
//  printf("pfunc = %p\n", *pfunc);
//  pfunc();
//
//  return 0;
//}

// コールバック関数のプロトタイプ宣言
typedef void (*Callback)(int result); // 型として定義

// サイコロの出目を決定する関数
int roll_dice() {
    return rand() % 6 + 1; // ランダム関数で1～6のどれかを返す
}

// 判定を行うコールバック関数
void judge_result(int result) {

    int input;

    printf("サイコロの出目が奇数(1)か偶数(2)か入力:");
    scanf_s("%d", &input);

    printf("判定中...\n");

    Sleep(3000);

    if ((result % 2 == 1 && input == 1) || (result % 2 == 0 && input == 2)) {
        printf("正解\n");
    } else {
        printf("不正解\n");
    }

    printf("サイコロの目は%d\n", result);
}

// メイン関数
int main() {

    srand((unsigned int)time(NULL)); // 乱数の初期化

    int dice_result = roll_dice();

    Callback callback = judge_result; // 実行したい関数のアドレス

    callback(dice_result); // サイコロの値を引数にして関数ポインタから関数を実行

    return 0;
}