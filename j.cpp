#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <math.h>
#include <time.h>
#include <queue>
#include <iostream>

using namespace std;

class Person
{
  public:

    int ID;
    double arrivalTime;

    Person(){};
    ~Person(){};

    void setPersonProperty(int Number, double Time)
    {
        ID = Number;
        arrivalTime = Time;
    };

  private:
    // int myNumber;
    // int weight;
};

double rnd_val(){
  double m;

  m = ((rand() + 0.5)/(RAND_MAX + 1.0));

  return m;
}

double rnd_exp(double lambda){
  double l;

  l = -1/lambda*log(1 - rnd_val());

  return l;
}

int main()
{
  Person toaruNingen[10000];
  double lambda = 10;
  int i = 0;
  int A[10000];
  int F[10000];
  int Uni=0;

  srand((int)time(NULL));

  for(i = 0; i <= 10000; i++)
  {
    A[i] = 0;
  }

  for(i = 0; i <= 10000; i++)
  {
    F[i] = 0;
  }

  toaruNingen[i].setPersonProperty(i, rnd_exp(lambda));

  A[(int)floor(toaruNingen[i].arrivalTime)]++;

  for(i = 1; i < 10000; i++)
  {
    toaruNingen[i].setPersonProperty(i, toaruNingen[i-1].arrivalTime+rnd_exp(lambda));

    A[(int)floor(toaruNingen[i].arrivalTime)]++;
    Uni=(int)floor(toaruNingen[i].arrivalTime);
  }

  for(i = 0; i <=Uni ; i++)
  {
    F[A[i]]++;
  }

  for(i = 0; i < 20; i++)
  {
    cout << F[i]*lambda/10000 << "\n";
  }

  return 0;
}
