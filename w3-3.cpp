//基本課題１

#include <random>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>




double rnd_val();
double rnd_exp(double lamda);

using namespace std;

class Person{
public:
	int ID;
  double arrivalTime;
  int PserverID;
  double deptTime;//会計が終わる時間
  double finTime;

	Person(){

	};

  ~Person(){
  };

	void setPersonProperty(int _ID,double _arrivalTime,double _PserverID,double _deptTime)
	{
    this->ID=_ID;
    this->arrivalTime=_arrivalTime;
    this->PserverID=_PserverID;
    this->deptTime=_deptTime;
	}
};


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
     this->Endtime=_l->deptTime;
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


class Event{
public:
  int eventID;//イベントのID
  double evTime;//イベントの発生時刻
  int evType;//イベントのタイプ
  Person* person;
  Server* server;

  Event(){}
  ~Event(){}

  void setEvent(int _eventID, double _evTime, int _eyType, Person* _person, Server* _server){
    this->eventID=_eventID;
    this->evTime=_evTime;
    this->evType=_eyType;
    this->person=_person;
    this->server=_server;
  }

  bool operator<(const Event& event1) const{
    return evTime>event1.evTime;
  }

};




#define EVENT_ARRIVAL 0 //到着イベント
#define EVENT_FINISH 1  //処理終了イベント


int main()
{
  std::priority_queue<Event> evPQ;    //イベント用の優先度付きキュー（イベント発生時間で優先度）

   //仮のPerson，Server
   Person man[10000];//客一万人
   Server s1(1,2.0);//レジ１つ, ID=1.0/ID=1
   Event e[10000];
   double random = 0.0;
   int seed = 0;
   int A[10000];
   int F[30];
   int Uni=0;
   int h=0;
   int o=0;
   int i=0;
   double J=0.0;
   int losnum=0;
   int knum=0;
  double lam=0.0;
  double curtime=0;

   srand((int)time(NULL) * seed++);

   lam=4.0;

 for(int u=0; u<10000; u++){
   A[u]=0;
 }
 for(int u=0; u<30; u++){
   F[u]=0;
 }

 man[i].setPersonProperty(i,rnd_exp(lam),1,0);
 e[i].setEvent(i, 0.0, EVENT_ARRIVAL, &man[i], &s1);
 A[(int)floor(man[i].arrivalTime)]++;

 cout<<"---------------------"<<lam<<endl;
 for(int i=1; i<10000; i=i*2){
   random=rnd_exp(lam);//randomで到着間隔
   curtime=curtime+random;//curtimeでsum
   man[i].arrivalTime=curtime;
   //cout<<curtime<<endl;
   man[i].setPersonProperty(i,curtime,1,0.0);
   double t=man[i].arrivalTime;
   e[i].setEvent(i,t, EVENT_ARRIVAL, &man[i], &s1);
   evPQ.push(e[i]);
   J=man[i].arrivalTime+rnd_exp(s1.m);
   e[i+1].setEvent(i,J, EVENT_FINISH,&man[i], &s1);
   evPQ.push(e[i+1]);
}

Event curEvent;
int nowTime=0;

 while (1)
 {
     //イベントキューから先頭要素を取り出し
     if (!evPQ.empty())
     {
         curEvent = evPQ.top();
         evPQ.pop();
     }
     else
     {

         break;
     }

     //イベントの種類で分岐
     switch (curEvent.evType)
     {
     case EVENT_ARRIVAL:
         printf("This event is ArrivalEvent eventID:%d at %f\n", curEvent.eventID, curEvent.evTime);
         //s1.accPerson(curEvent.evTime,curEvent.person);
         break;

     case EVENT_FINISH:
         printf("This event is FinishEvent eventID:%d at %f\n", curEvent.eventID, curEvent.evTime);
        // s1.release(curEvent.evTime);
         ++losnum;
         break;
     }
 }

 cout<<"this is rate of Los"<<losnum/10000.0<<endl;


	return 0;
}

double rnd_val() {
	double rnd;
	rnd = (rand() + 0.5) / (RAND_MAX + 1.0);
	return rnd;
}



double rnd_exp(double lamda){
  double rnd;
  rnd=-1.0 / lamda * log(rnd_val());
  return rnd;
}
