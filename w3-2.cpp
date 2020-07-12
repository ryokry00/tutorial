//基本課題１

#include <random>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include "person.h"
#include "event.h"
#include "server.h"




double rnd_val();
double rnd_exp(double lamda);

using namespace std;




#define EVENT_ARRIVAL 0 //到着イベント
#define EVENT_FINISH 1  //処理終了イベント


int main()
{
  std::priority_queue<Event> evPQ;    //イベント用の優先度付きキュー（イベント発生時間で優先度）

   //仮のPerson，Server
   Person p1;
   Server s1(1,2.0);

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
