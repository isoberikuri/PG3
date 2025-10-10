#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <list>

using namespace std;

int main() {

    //==============================
    // 1970年の山手線（西日暮里・高輪ゲートウェイなし）
    //==============================
    list<const char*> lst1970{
        "Tokyo","Kanda","Akihabara","Okachimachi","Ueno","Uguisudani",
        "Nippori","Tabata","Komagome","Sugamo","Otsuka","Ikebukuro",
        "Mejiro","Takadanobaba","Shin-Okubo","Shinjuku","Yoyogi",
        "Harajuku","Shibuya","Ebisu","Meguro","Gotanda","Osaki",
        "Shinagawa","Tamachi","Hamamatsucho","Shimbashi","Yurakucho\n"
    };

    // --- 1970年の駅一覧を表示 ---
    printf("1970\n");
    for (const char* name : lst1970)
    {
        // 各駅名を1行ずつ出力
        printf("%s", name);
    }

    //==============================
    // 2019年の山手線（西日暮里追加）
    //==============================
    
    // 1970年のリストをコピーしてスタート
    list<const char*> lst2019 = lst1970; 

    // --- 「Nippori」の次に「Nishi-Nippori（西日暮里）」を挿入 ---
    for (auto it = lst2019.begin(); it != lst2019.end(); ++it)
    {
        // 「Nippori」を見つけたら
        if (strcmp(*it, "Nippori") == 0)
        { 
            // 「Nippori」を見つけたら
            ++it;                   
            // 挿入
            lst2019.insert(it, "Nishi-Nippori");  
            // 処理を終了（1回だけ）
            break;                          
        }
    }

    // --- 2019年の駅一覧を表示 ---
    printf("\n2019\n");
    for (const char* name : lst2019)
    {
        printf("%s", name);
    }

    //==============================
    // 2022年の山手線（西日暮里＋高輪ゲートウェイ追加）
    //==============================
    
     // 2019年のリストをコピー
    list<const char*> lst2022 = lst2019; 

    // --- 「Shinagawa」の次に「Takanawa Gateway（高輪ゲートウェイ）」を挿入 ---
    for (auto it = lst2022.begin(); it != lst2022.end(); ++it)
    {
        // 「Shinagawa」を見つけたら
        if (strcmp(*it, "Shinagawa") == 0)
        {  
            // その次の位置に移動して
            ++it;      
            // 挿入
            lst2022.insert(it, "Takanawa Gateway"); 
            // 処理を終了
            break;                              
        }
    }

    // --- 2022年の駅一覧を表示 ---
    printf("\n2022\n");
    for (const char* name : lst2022)
    {
        printf("%s", name);
    }

    return 0;
}