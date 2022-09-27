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
  static DataTime t;
  strptime(time_string, "%d %H:%M:%S", &t);
  return &t;
}