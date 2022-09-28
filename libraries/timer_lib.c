#define __USE_XOPEN // needed for strptime
#define _GNU_SOURCE // needed for strptime
#include <stdio.h> //Для printf
#include <time.h>  //Для clock_gettime
#include <string.h>
#include "../headers/timer_lib.h"

DataTime * setCurrentTime(){
  time_t rawtime;
  DataTime *current_time;
  time( &rawtime );
  current_time = localtime( &rawtime );
  return current_time;
}

DataTime * getTime(char* time_string) {
  static DataTime t;
  strptime(time_string, "%y-%m-%d %H:%M:%S", &t);
  return &t;
}

char printWeekDay(DataTime * DT) {
  printf("Week day:  %d\n",DT->tm_wday);
  return (char)(DT->tm_wday + 48);
}

DataTime * after(char* time_string) {
  // get current time
  time_t rawtime;
  DataTime *time_point;
  time( &rawtime );
  time_point = localtime( &rawtime );

  // parse the time_string
  DataTime addinterval;
  strptime(time_string, "%d %H:%M:%S", &addinterval);

  // Add time interval
  time_point->tm_mday += addinterval.tm_mday;
  time_point->tm_hour += addinterval.tm_hour;
  time_point->tm_min += addinterval.tm_min;
  time_point->tm_sec += addinterval.tm_sec;
  mktime(time_point); //normalize result

  return time_point;
}

DataTime * before(char* time_string) {
  // get current time
  time_t rawtime;
  DataTime *time_point;
  time( &rawtime );
  time_point = localtime( &rawtime );

  // parse the time_string
  DataTime addinterval;
  strptime(time_string, "%d %H:%M:%S", &addinterval);

  // Subtract time interval
  time_point->tm_mday -= addinterval.tm_mday;
  time_point->tm_hour -= addinterval.tm_hour;
  time_point->tm_min -= addinterval.tm_min;
  time_point->tm_sec -= addinterval.tm_sec;
  mktime(time_point); //normalize result

  return time_point;
}

Timer * getTimer(long long dd, int hh, int min, int sec, int nano) {
  static Timer t_time;
  t_time.dd = dd;
  t_time.hh = hh;
  t_time.min = min;
  t_time.sec = sec;
  t_time.nano = nano;

  return &t_time;
}

void addTm(Timer* t1, const Timer* t2) {
  long long temp;

  temp = t1->nano + t2->nano;
  t1->nano = temp % 1'000'000'000;
  temp = t1->sec + t2->sec + temp / 1'000'000'000;
  t1->sec = temp % 60;
  temp = t1->min + t2->min + temp / 60;
  t1->min = temp % 60;
  temp = t1->hh + t2->hh + temp / 60;
  t1->hh = temp % 24;
  t1->dd = t1->dd + t2->dd + temp / 24;
}