#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
  int a=2;
  int b=3;
  int c=4;
  string d="hello";
  string f="world";
  string &e=d;
  string* ptr=&f;
  string full=d+f;
  string fullname;


int i=0;
*ptr="UHHHH";

cout<<*ptr<<endl;
cout<<f<<endl;



  return 0;
}
