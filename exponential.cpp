#include <random>
#include <fstream>
#include <iostream>

using namespace std;
int main()
{
  int A[10000];
  int Uni=0;
  std::random_device seed_gen;
  std::default_random_engine engine(seed_gen());

  std::exponential_distribution<> dist(2.0);
  for(int u=0; u<10000; ++u){
    A[u]=0;
  }

  for (std::size_t n = 0; n < 10000; ++n) {
    int result = dist(engine);
    Uni=(int)floor(result);//curtimeの整数部分を下に単位T＝１で一つの区間に何人到着したか数える
    A[Uni]=A[Uni]+1;
  }
  for(int u=0; u<100; ++u){
    cout<<A[u]/10000.0<<endl;
  }
  return 0;
}
