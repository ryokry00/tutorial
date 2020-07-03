#include <random>
#include <iostream>
#include <iomanip>

using namespace std;

double rnd_val();

double base=0.0;

int main()
{
	double sumval = 0.0;
  int seed=0;
  double x=0.0;
  double y=0.0;
  double z=0.0;
  int num=0;

for(int u=0; u<100; u++){
  double round=0.0;
  num=0;
	for (int i = 0; i < 100000; i++)
	{
    srand((int)time(NULL) * seed++);
		x=rnd_val();
    y=rnd_val();

    z=sqrt(x*x+y*y);

    if(z<1.0){
      num++;
    }
	}
  round=4*num/100000.0;
  cout<<round<<endl;
}
	return 0;
}


double rnd_val() {
	double rnd;
	rnd = (rand()+0.5) / (RAND_MAX+1.0);
	return rnd;
}
