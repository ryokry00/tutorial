//基本課題1

#include <random>
#include <iostream>

double rnd_val();
double rnd_exp(double lamda);

using namespace std;


class Person{
public:
	int ID;
  int arrivalTime;

	Person(int _ID){
    ID=_ID;
	};

  ~Person(){
  };

	void setPersonProperty(int _arrivalTime)
	{
    arrivalTime=_arrivalTime;
	}
};


int main()
{
	int random = 0;
	int seed = 0;
	int numER[1000];
  int F[10000];
  int numUni=0;
  int h=0;
  int o=0;
 double lam=0.0;
 int curtime=0;

  double g[3]={1.0,0.25,0.1};

  for(int u=0; u<1000; ++u){
    numER[u]=0;
  }
  for(int u=0; u<10000; ++u){
    F[u]=0;
  }

for(int i=0; i<3; ++i){
lam=g[i];
cout<<"---------------------"<<lam<<endl;
for(int i=0; i<10000; i++){
  srand((int)time(NULL) * ++seed);
  random=rnd_exp(lam);
  curtime+=random;/////////////////this is factor
  //cout<<random<<endl;
  Person(i).setPersonProperty(curtime);
  numUni=curtime;
  ++numER[numUni];
}

for(int u=0; u<1000; u++){
  o=numER[u];
  cout<<o<<endl;
  F[o]++;
}

cout<<"----------------"<<endl;
for(int u=0; u<1000; u++){
  cout<<"F"<<F[u]<<endl;
}


}
	return 0;
}

double rnd_val() {
	double rnd;
	rnd = (rand() + 0.5) / (RAND_MAX + 1.0);

	return rnd;
}



double rnd_exp(double lamda){
  double rnd;
  rnd=-1.0 / lamda * log(rnd_val());

  return rnd;
}
