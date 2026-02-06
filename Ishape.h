#pragma once
#include <stdio.h>

class IShape {
public:
	virtual void Size() = 0; // 面積を計算
	virtual void Draw() = 0; // 面積を表示
protected:
	const char* name;
	float radius = 4; // 半径
	int wide = 2;     // 横幅
	int height = 3;   // 縦幅
};