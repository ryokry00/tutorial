#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <math.h>
#include <time.h>
#include <queue>
#include <iostream>

#define EVENT_ARRIVAL 0
#define EVENT_FINISH 1
#define UNDEFINED -1

using namespace std;

double rnd_val();
double rnd_exp(double lambda);

class Person
{
  public:

    int personID;
    double arrivalTime;
    double deptTime;
    int serverID;

    Person(){};
    ~Person(){};

    void setPersonProperty(int _personID, double _arrivalTime, double d_Time, int s_number)
    {
        personID = _personID;
        arrivalTime = _arrivalTime;
        deptTime = d_Time;
        serverID = s_number;
    };

  private:
    // int myNumber;
    // int weight;
};

class Server
{
public:

    int serverID;
    Person* p;
    double finishTime;
    double mu;
    bool acceptableFlag = true;

    Server(int _ID, double _mu){
      serverID = _ID;
      mu = _mu;
      finishTime = 0.0;
    };
    ~Server() {};

    int acceptPerson(double curTime, Person* _p)
    {
      if (acceptableFlag)
      {
        p = _p;
        p->serverID = serverID;
        finishTime = curTime + rnd_exp(mu);
        acceptableFlag = false;

        return 1;
      }
      else
      {
        _p->serverID = -1;
        _p->deptTime = -1;

        return 0;
      }
    }

    void releaseServer(double l_Time)
    {
      p->deptTime = l_Time;
      acceptableFlag = true;
    }
};

class Event
{
  public:

    int eventID;
    double evTime;
    int evType;
    Person* person;
    Server* server;

    Event(int _eventID, double _evTime, int _evType, Person* _person, Server* _server)
    {
      eventID = _eventID;
      evTime = _evTime;
      evType = _evType;
      person = _person;
      server = _server;
    }

    Event() {};
    ~Event() {}

    bool operator<(const Event& event1) const
    {
      return evTime > event1.evTime;
    };
};

double rnd_val(){
  double m;

  m = ((rand() + 0.5)/(RAND_MAX + 1.0));

  return m;
}

double rnd_exp(double lambda){
  double l;

  l = -1.0/lambda*log(1.0 - rnd_val());

  return l;
}

int main()
{
  int mu = 1;
  int lambda = 1;

  std::priority_queue<Event> evPQ;

  for(mu=1; mu<=10; mu++)
  {
    for(lambda=1; lambda<10; lambda=lambda+4)
    {
      int eventID = 0;
      Server svr0(0, mu);

      Event tmpEvent;
      Event curEvent;

      double curTime = 0.0;
      const int totalPerson = 10000;
      int numPerson = 0;
      int lossCount = 0;

      Person* persons = new Person[totalPerson];

      persons[numPerson].setPersonProperty(numPerson, 0.0, UNDEFINED, UNDEFINED);
      tmpEvent = Event(eventID, persons[numPerson].arrivalTime, EVENT_ARRIVAL, &persons[numPerson], NULL);
      evPQ.push(tmpEvent);
      eventID++;

      while(numPerson < totalPerson)
      {
        if(!evPQ.empty())
        {
          curEvent = evPQ.top();
          evPQ.pop();
        }
        else
        {
          break;
        }

        switch (curEvent.evType)
        {
          case EVENT_ARRIVAL:
          if(svr0.acceptPerson(curEvent.evTime, curEvent.person)==1)
          {
            tmpEvent = Event(eventID, svr0.finishTime, EVENT_FINISH, curEvent.person, &svr0);
            eventID++;
            evPQ.push(tmpEvent);
          }
          else
          {
            lossCount++;
          }

          persons[numPerson].setPersonProperty(numPerson, curEvent.evTime + rnd_exp(lambda), UNDEFINED, UNDEFINED);

          evPQ.push(Event(eventID++, persons[numPerson].arrivalTime, EVENT_ARRIVAL, &persons[numPerson], NULL));
          numPerson++;
          break;

          case EVENT_FINISH:
          curEvent.server -> releaseServer(curTime);
          break;
        }
      }
      printf("lossRate = %lf, mu = %d, lambda = %d\n", (double)lossCount/(double)totalPerson, mu, lambda);
    }
  }
  return 0;
}
