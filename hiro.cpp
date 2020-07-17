#include <stdio.h>
#include <sys/time.h>
#include <random>
#include <math.h>
#include <queue>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define EVENT_ARRIVAL 0
#define EVENT_FINISH 1

//一様乱数
double rnd_val(){
  double a;
  a = (rand()+0.5)/(RAND_MAX + 1.0);
   return a;
}
//指数分布
double rnd_exp(double lambda){
  double exp;
  exp = -1 /(lambda) *log(1-rnd_val());
  return exp;
}

//Person,Server,Eventクラス
class Person{
public:

  Person() {};
  ~Person() {};

  int personID;
  double arrivalTime;
  double deptTime;
  int serverID;

  void setPersonPropaty(int _personID,double _arrivalTime,double _deptTime,int _serverID){
    personID = _personID;
    arrivalTime = _arrivalTime;
    deptTime = _deptTime;
    serverID = _serverID;
    //printf("personID %d, arrivalTime %.1f, deptTime %.1f, serverID %d\n", personID, arrivalTime,deptTime,serverID);
  }
};

class Server{
public:

  int serverID;
  Person* p;
  double finishTime;
  double mu;
  bool acceptableFlag;
  int loss;

  Server(int _ID, double _mu) {
    serverID = _ID;
    mu = _mu;
    finishTime = 0.0;
    loss=0;
  };

  ~Server() {};

  //acceptServer
  int acceptPerson(double curTime, Person* _p){

    if (acceptableFlag)
    {
      //accept
      p = _p;
      p->serverID = 1;
      finishTime = curTime + rnd_exp(mu);
      acceptableFlag = 0;

      return 1;
    }
    else{
      //disacceptServer
      _p->serverID=-1;
      _p->deptTime=-1;

      loss++;
      return 0;
    }
  }

  void releaseServer(double curTime){
    p->deptTime =curTime;
    acceptableFlag = true;
  }
 };

class Event{
 public:
   int eventID;
   double evTime;
   int evType;
   Person* person;
   Server* server;

   Event() {};

   ~Event() {};

   void getEvent(int _eventID, double _evTime, int _evType,Person* _person, Server* _server)
   {
     this->eventID = _eventID;
     this->evTime = _evTime;
     this->evType = _evType;
     this->person = _person;
     this->server = _server;
   }

   bool operator<(const Event& event1) const
   {
     return evTime > event1.evTime;
   }

 };


int main()
{
  std::priority_queue<Event> evPQ;
  Event e[10000];
  Person Son[10000];
  double mu=5.0;
  double lambda=2.0;
  Server  s1(1,mu);
  int seed=0;
  int totalPerson = 10000;
  int numPerson =0;
  int eventID=0;
  double random=0.0;
  double curtime=0.0;
  double B=0;
  double lossP;

  srand((int)time(NULL) * seed++);


    double u=0.0;
    int s=0;
    random=rnd_exp(lambda);
    curtime=curtime+random;
    Son[numPerson].arrivalTime=curtime;
    u=Son[numPerson].arrivalTime;
    Son[numPerson].setPersonPropaty(numPerson,rnd_exp(lambda),1,0);
    e[numPerson].getEvent(numPerson,u,EVENT_ARRIVAL,&Son[numPerson],&s1);
    evPQ.push(e[numPerson]);



  Event curEvent;


  if(!evPQ.empty()){
      curEvent = evPQ.top();
      evPQ.pop();
    }
  else{
      break;
    }

    switch (curEvent.evType) {
      case EVENT_ARRIVAL:
        // printf("This event is ArrivalEvent EventID:%d at %f\n",curEvent.eventID, curEvent.evTime);
        s1.acceptPerson(curEvent.evTime,curEvent.person);
        e[curEvent.person->personID].getEvent(curEvent.person->personID,curEvent.server->finishTime,EVENT_FINISH,curEvent.person,&s1);
        evPQ.push(e[curEvent.person->personID]);
        break;

      case EVENT_FINISH:
        s1.releaseServer(curEvent.evTime);
        // printf("This event is FinishEvent EventID:%d atr %f\n",curEvent.eventID,curEvent.evTime);
        break;
    }
  }

  //lossPropability
  lossP = s1.loss / 10000.0;
  printf("ロス率 %.1f\n",lossP);

return 0;
}
