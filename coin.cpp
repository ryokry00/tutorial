#include <iostream>

using namespace std;
#define MAX 10

  int a=0;
  int numa=0;
  int b=0;
  //int numb=0;
  int c=0;
//  int numc=0;
  int x=0;
  int n=0;
  int s=0;
  int num=0;

  int coin[MAX][3];

int how(int sum,int u,int num){
  int mov=0;
  int n=0;
  if(sum>=u){
  do{
  sum=sum-u;
  ++mov;
}while(num>mov&&sum>0);
}else{
  return 0;
}
  return mov;
}

int main(){
  coin[0][0]=500;
  coin[0][1]=100;
  coin[0][2]=50;

cin>>x;

cin>>a;
cout<<how(x,500,a)<<endl;
cin>>b;
cout<<how(x,100,b)<<endl;
cin>>c;
cout<<how(x,50,c)<<endl;






  return 0;

}
