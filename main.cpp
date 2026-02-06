#include <stdio.h>

template <typename Type> Type Min(Type a, Type b) {
    // 関数テンプレート：引数aとbを比較して小さい方を返す
    if (a > b) {
        return static_cast<Type>(b);
    } else {
        return static_cast<Type>(a);
    }
}

int main() {
    // 計算と結果出力
    printf("%d\n", Min<int>(128, 256));       // 整数の比較
    printf("%f\n", Min<float>(52.5f, 55.0f)); // 単精度浮動小数点の比較
    printf("%lf\n",
        Min<double>(3.14159265, 2.7182818281)); // 倍精度浮動小数点の比較

    return 0;
}