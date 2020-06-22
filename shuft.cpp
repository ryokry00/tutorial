#include <iostream>
#include <cmath>

using namespace std;

int main(){

  int x=0;
  char s;

  cin>>x;
  std::cout<<"x:"<<std::hex<<x<<endl;
  cin>>s;

  if(s=='r'){
    unsigned x=x/2;
    std::cout<<"x>>2:"<<std::hex<<x<<endl;
  }else{
    x=x*2;
    std::cout<<"x<<2:"<<std::hex<<x<<endl;
  }




  return 0;

}
