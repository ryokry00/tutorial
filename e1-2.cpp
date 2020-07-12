//基本課題1

#include <random>
#include <iostream>
#include <fstream>

double rnd_val();
double rnd_exp(double lamda);

using namespace std;


class Person{
public:
	int ID;
  double arrivalTime;

	Person(){

	};

  ~Person(){
  };

	void setPersonProperty(int _ID,double _arrivalTime)
	{
    ID=_ID;
    arrivalTime=_arrivalTime;
	}
};


int main()
{
  Person man[10000];
	double random = 0.0;
	int seed = 0;
	int A[10000];
  int F[30];
  int Uni=0;
  int h=0;
  int o=0;
 double lam=0.0;
 double curtime=0.0;


  lam=4.0;

for(int u=0; u<10000; u++){
  A[u]=0;
}
for(int u=0; u<30; u++){
  F[u]=0;
}

cout<<"---------------------"<<lam<<endl;
for(int i=1; i<10000; i++){
  srand((int)time(NULL) * seed++);
  random=0.0;
  random=rnd_exp(lam);//randomで到着間隔
  curtime=man[i-1].arrivalTime+random;//curtimeでsum
  //cout<<curtime<<endl;
  man[i].setPersonProperty(i,curtime);
  Uni=(int)floor(man[i].arrivalTime);//curtimeの整数部分を下に単位T＝１で一つの区間に何人到着したか数える
  A[Uni]=A[Uni]+1;
}
cout<<Uni<<endl;

for(int u=0; u<Uni; ++u){
  o=A[u];
  //cout<<o<<endl;
  ++F[o];
}

for(int u=0; u<30; ++u){
  cout<<"F"<<u<<" "<<F[u]*lam/10000.0<<endl;//単位あたりの個数の確率
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
