//課題　2-0
#include <random>
#include <iostream>


double rnd_val();
double rnd_uni(int a, double b);

using namespace std;


class Dice {
public:
	int ID;
	int value;

	Dice(int _ID)
	{
		ID = _ID;
	};

  ~Dice(){
  };

	int Roll()
	{
		value =(int)(rnd_val()*10000)%6+1;
		return value;
	}
};


int main()
{
	Dice d1(1);
	int sum = 0;
	int seed = 0;
  int eachD1=0;
  int eachD2=0;


	for (int j = 0; j < 100; j++)
	{
		srand((int)time(NULL) * seed++);
		int numRoll = 1;


    eachD1=d1.Roll();

		cout<<"average of"<<numRoll<<"times rolling"<<eachD1<<endl;
	}

	return 0;
}


double rnd_val() {
	double rnd;
	rnd = (rand() + 0.5) / (RAND_MAX + 1.0);

	return rnd;
}
