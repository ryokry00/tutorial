#include <iostream>

using namespace std;


int N=0;
int num=0;

int A[201];


int main(){

  cin>>N;

  for(int i=0; i<N; i++){
    cin>>A[i];
  }

  do{
    bool s=false;
    for(int i=0; i<N; i++){
     if(A[i]%2!=0){
       s=true;
     }
    }
    if(s==true){
      break;
    }
    for(int i=0; i<N; i++){
      A[i]/=2;
    }
    ++num;
  }while(0);

  cout<<num<<endl;


  return 0;
}
