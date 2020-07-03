//課題2-2

#include <random>
#include <iostream>


#define size 64




double rnd_val();
double rnd_uni(int a, int b);

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

	int Roll(int turn)
	{
    if(turn==0){
    value =(int)(rnd_uni(0,1)*10000)%6+1;
    return value;
  }else{
    value =(int)(rnd_val()*10000)%6+1;
    return value;
  }
	}
};


int main()
{

  int turn=0;
  int q=0;
  int sum = 0;
  int seed = 0;
  double avg=0;
  string rollkind[2];
  rollkind[0]="rnd_uni(int a, int b)";
  rollkind[1]="rnd_val()";
	int numER[70];




for(int i=2; i<12; i++){
  int max=0;
  max=i;

  int each[max];

	for(int u=0; u<70; u++){
		numER[u]=0;
	}



 cout<<"which one do you want to use?"<<endl;
 cout<<"rnd_uni→0"<<endl;
 cout<<"rnd_val→1"<<endl;
 cin>>turn;
 cout<<"-------------------------------------------"<<i<<endl;

	for (int j = 0; j < 10000; j++)
	{
		srand((int)time(NULL) * seed++);
		int num = 100;
		sum = 0;

      for(int j=0; j<max; j++){
        each[j]=Dice(j).Roll(turn);
        sum+=each[j];
      }
		numER[sum]+=1;
		//cout<<sum<<endl;
	}
  for(int u=0; u<70; u++){
		cout<<numER[u]<<endl;
	}
}

	return 0;
}


double rnd_val() {
	double rnd;
	rnd = (rand() + 0.5) / (RAND_MAX + 1.0);

	return rnd;
}

double  rnd_uni(int a, int b){
  double rnd;
  rnd=a + (b - a) * rnd_val();

	return rnd;
}
