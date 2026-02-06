#include <cstdio>

using namespace std;

// 動物クラス（抽象クラス）
class Animal {
public:
	// 鳴く関数（純粋仮想関数）
	virtual void sound() const = 0;
};

// 犬クラス（Animalを継承）
class Dog : public Animal {
public:
	void sound() const override { printf("イヌ鳴き声：ワン\n"); }
};

// 猫クラス（Animalを継承）
class Cat : public Animal {
public:
	void sound() const override { printf("ネコ鳴き声：ニャー\n"); }
};

int main() {
	// 動物クラスのポインタ
	Animal* animal1 = new Dog();
	Animal* animal2 = new Cat();

	animal1->sound();
	animal2->sound();

	delete animal1;
	delete animal2;

	return 0;
}