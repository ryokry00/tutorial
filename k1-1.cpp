#include <stdio.h>
#include <random>
#include <iostream>

using namespace std;

double rnd_val();
double base=0.0;

int main()
{
	double sumUni01 = 0.0;

	srand(18141367);

	for (int i = 0; i < 1000; i++)
	{
    base=rnd_val();
		sumUni01 += base;
	}
  cout<<"average rnd_val:"<<sumUni01 / 1000.0<<endl;


	return 0;
}


double rnd_val() {
	double rnd;
	rnd = (rand() + 0.5) / (RAND_MAX + 1.0);
  cout<<rand()<<endl;
  cout<<RAND_MAX<<endl;
	return rnd;
}
