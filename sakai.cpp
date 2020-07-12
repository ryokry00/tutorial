
#include <random>
#include <iostream>

using namespace std;
double rnd_val();
double rnd_uni(double a, double b);
double rnd_exp(double lambda);
double roll();

int main()
{
  int i, j, k;
  int d1 = 0;
  int sumHist[61];
  int seed=0;



  // srand(18141297);
  for(i=2; i<12; i++)
  {
    int max=0;
    max=i;

    for(j=0; j<61; j++)
    {
      sumHist[j] = 0;
    }

    for(k=0; k<10000; k++)
    {
      srand((int)time(NULL) * seed++);
      int sum = 0;
      for(int u=0;  u<max; u++)
      {
        d1 = roll();
        sum += d1;
      }

      sumHist[sum]++;
    }

    for(j=0; j < 61; j++)
    {
      printf("[%d],%d,\n", i, sumHist[j]);
    }

  }
  return 0;
}

double rnd_val(){
  double m;

  m = ((rand() + 0.5)/(RAND_MAX + 1.0));

  return m;
}


double roll(){
  int a;
  a = (int)(rnd_val()*10000)% 6 + 1;
  return a;
}
