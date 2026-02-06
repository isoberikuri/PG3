#include "Circle.h"
#include "IShape.h"
#include "Rectangle.h"
#include <stdio.h>

int main(void) {

    IShape* shape[2]; // 図形クラスのポインタ型配列

    shape[0] = new Circle;    // 円クラス
    shape[1] = new Rectangle; // 四角形クラス

    printf("円の半径:4\n短形の底辺:2\n短形の高さ:3\n");

    // 面積を計算
    for (int i = 0; i < 2; i++)
        shape[i]->Size();

    printf("\n");

    // 面積を画面に表示
    for (int i = 0; i < 2; i++)
        shape[i]->Draw();

    // メモリ解放（重要）
    for (int i = 0; i < 2; i++)
        delete shape[i];

    return 0;
}