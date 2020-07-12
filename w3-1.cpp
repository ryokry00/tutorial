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
 bool Flag=true;
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


class Event{
public:
  int eventID;//イベントのID
  double evTime;//イベントの発生時刻
  int evType;//イベントのタイプ
  Person* person;
  Server* server;

  Event(int _eventID, double _evTime, int _eyType, Person* _person, Server* _server){
    this->eventID=_eventID;
    this->evTime=_evTime;
    this->evType=_eyType;
    this->person=_person;
    this->server=_server;
  }

  Event(){}
  ~Event(){}

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
   Person p[10000];//客一万人
   Server s1(1,2.0);//レジ１つ


   //客①の到着イベント
   Event tempEvent1_1(0, 0.0, EVENT_ARRIVAL, &p1, &s1);
   evPQ.push(tempEvent1_1);

   //客①の終了イベント
   Event tempEvent1_2(1, 10.0, EVENT_FINISH, &p1, &s1);
   evPQ.push(tempEvent1_2);

   //客②の到着イベント
   Event tempEvent2_1(2, 2.0, EVENT_ARRIVAL, &p1, &s1);
   evPQ.push(tempEvent2_1);

   //客②の終了イベント
   Event tempEvent2_2(3, 5.0, EVENT_FINISH, &p1, &s1);
   evPQ.push(tempEvent2_2);

   //客③の到着イベント
   Event tempEvent3_1(4, 6.0, EVENT_ARRIVAL, &p1, &s1);
   evPQ.push(tempEvent3_1);

   //客③の終了イベント
   Event tempEvent3_2(5, 12.0, EVENT_FINISH, &p1, &s1);
   evPQ.push(tempEvent3_2);

   Event curEvent;

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
           break;

       case EVENT_FINISH:
           printf("This event is FinishEvent eventID:%d at %f\n", curEvent.eventID, curEvent.evTime);
           break;
       }
   }

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
