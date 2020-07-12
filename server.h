#ifndef _SERVER_H_
#define _SERVER_H_

#include <iostream>
#include "person.h"
#include "event.h"

using namespace std;


class Server{
public:
 int serverID;
 double m;
 bool Flag;
 Person* l;
 double Endtime;

 Server(int _n,double _m){
   serverID=_n;
   m=_m;
   Endtime=0.0;
 };

 ~Server(){};

 int accPerson(double curtime, Person* _l){
   if(Flag){
     //受入可能　Flag=true=1
     this->l=_l;
     l->PserverID=serverID;
     this->Endtime=curtime+rnd_exp(this->m);
     this->Flag=false;
     return 1;
   }else{
     //受入不可　Flag＝faulse＝0
     _l->PserverID=-1;
     _l->deptTime=-1;
     return 0;
   }
 }

 void release(double Time){
   l->deptTime=Time;
   this->Flag=true;
 }

};

#endif
