
#ifndef _EVENT_H_
#define _EVENT_H_

#include <iostream>
#include "person.h"
#include "server.h"
using namespace std;


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


#endif
