#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <math.h>
#include <time.h>



double rnd_val();
double rnd_uni(double a, double b);

using namespace std;


class Dice {
public:
	int ID;
	int value;

	Dice(int _ID)
	{
		ID = _ID;
	};

	int Roll()
	{
		value = xxx;
		return value;
	}
};


int main()
{
	Dice d1(1);
	Dice d2(2);
	int sum = 0;
	int seed = 0;


	for (int j = 0; j < 100; j++)
	{
		srand((int)time(NULL) * seed++);
		int numIter = xxx;

		sum = 0;


		for (int i = 0; i < numIter; i++)
		{
			d1.Roll();
			d2.Roll();
			sum += xxx;
		}


		avg = xxx;
		printf("%d,%f\n", numIter, avg);
	}

	return 0;
}



double rnd_val() {
	double rnd;
	rnd = (rand() + 0.5) / (RAND_MAX + 1.0);

	return rnd;
}


double rnd_uni(double a, double b) {
	double rnd;

	rnd = a + (b - a)*rnd_val();

	return rnd;
}
