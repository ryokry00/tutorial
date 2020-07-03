//課題　2-1 
#include <random>
#include <iostream>




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
	Dice d1(1);
	Dice d2(2);
	double sum = 0.0;
	int seed = 0;
  double avg=0;
  int eachD1=0;
  int eachD2=0;

  int turn=0;

  string rollkind[2];
  rollkind[0]="rnd_uni(int a, int b)";
  rollkind[1]="rnd_val()";

 cout<<"which one do you want to use?"<<endl;
 cout<<"rnd_uni→0"<<endl;
 cout<<"rnd_val→1"<<endl;
 cin>>turn;


	for (int j = 0; j < 100; j++)
	{
		srand((int)time(NULL) * seed++);
		int num = 100;
		sum = 0;

		for (int i = 0; i < num; i++)
		{
			eachD1=d1.Roll(turn);
			eachD2=d2.Roll(turn);

			sum+=eachD1+eachD2;
		}



		avg = sum/num;
		cout<<"average of"<<num<<"times rolling(with "<<rollkind[turn]<<")"<<"is"<<avg<<endl;
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
