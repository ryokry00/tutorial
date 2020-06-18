#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <math.h>
#include <time.h>


//乱数生成用関数
double rnd_val();
double rnd_uni(double a, double b);

using namespace std;

//サイコロの目（1～6）の乱数を生成するクラス
class Dice {
public:
	int ID;
	int value;

	Dice(int _ID)
	{
		ID = _ID;
	};

	//課題1で作成した乱数（0～1）を6で割った商は0-5の値を取る。
	//これに+1して1～6となる。最後に、整数型に変換する。
	int Roll()
	{
		value = (int)(rnd_val()*10000)%6 +1;

		return value;
	}
};


int main()
{
	Dice d1(1);
	Dice d2(2);
	int sum = 0;
	int seed = 0;

	//大数の法則
	for (int j = 0; j < 100; j++)
	{
		srand((int)time(NULL) * seed++);
		int numIter = xxx;

		//初期化
		sum = 0;

		//指定された回数、サイコロを回して積算する。
		for (int i = 0; i < numIter; i++)
		{
			d1.Roll();
			d2.Roll();
			sum += xxx;
		}

		//大数の法則の結果出力
		avg = xxx;
		printf("%d,%f\n", numIter, avg);
	}

	return 0;
}


// (0,1) の一様乱数
double rnd_val() {
	double rnd;
	rnd = (rand() + 0.5) / (RAND_MAX + 1.0);

	return rnd;
}

// (a,b) の一様乱数
double rnd_uni(double a, double b) {
	double rnd;

	rnd = a + (b - a)*rnd_val();

	return rnd;
}
