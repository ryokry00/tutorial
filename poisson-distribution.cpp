#include <iostream>
#include <random>
#include <fstream>

using namespace std;

int main(){
  int F[30];
  std::random_device seed_gen;
  std::default_random_engine engine(seed_gen());

  std::poisson_distribution<> dist(10.0);
  for(int i=0; i<30; i++){
    F[i]=0;
  }
 for (std::size_t n = 0; n < 10000; ++n) {
   int result = dist(engine);
   ++F[result];
 }

 for(int i=0; i<30; i++){
   cout<<F[i]/10000.0<<endl;
 }

  return 0;

}
