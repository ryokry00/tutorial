#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include "server.h"
#include "event.h"

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

#endif
