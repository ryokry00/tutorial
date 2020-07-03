// １−３　uniform distribution
#include <random>
#include <iostream>

using namespace std;

double rnd_val();
double rnd_uni(int a,int b);
double rnd_exp(double lamda);

double base=0.0;

int main()
{
	double sumval = 0.0;
  double sumuni = 0.0;
  double sumexp = 0.0;
	int numER[1000];
	int numUni=0;
	for(int u=0; u<1000; u++){
		numER[u]=0;
	}

	srand(18141367);

	for (int i = 0; i < 1000; i++)
	{
	//	sumval = rnd_val();
    sumuni = rnd_uni(1,2);
		//cout<<sumuni<<endl;
		numUni=sumuni*100;
    numER[numUni]++;
    //sumexp = rnd_exp(0.5);
	}
	cout<<RAND_MAX<<endl;
  /*cout<<"average of random value(rnd_val()):"<<sumval / 1000.0<<endl;
  cout<<"average of random value(rnd_uni()):"<<sumuni / 1000.0<<endl;
  cout<<"average of random value(rnd_exp()):"<<sumexp / 1000.0<<endl;*/
	for(int u=0; u<1000; u++){
		cout<<numER[u]<<endl;
	}


	return 0;
}


double rnd_val() {
	double rnd;
	rnd = (rand()+0.5) / (RAND_MAX+1.0);
	return rnd;
}

double  rnd_uni(int a, int b){
  double rnd;
  rnd=a + (b - a) * rnd_val();

	return rnd;
}

double rnd_exp(double lamda){
  double rnd;
  rnd=-1.0 / lamda * log(rnd_val());

  return rnd;
}
