#define __USE_XOPEN // needed for strptime
#define _GNU_SOURCE // needed for strptime
#include <stdio.h> //Для printf
#include <stdlib.h>
#include <time.h>  //Для clock_gettime
#include <string.h>
#include "../headers/timer_lib.h"

void setCurrentTime(DataTime *current_time){
  time_t rawtime;
  time( &rawtime );
  localtime_r(&rawtime, current_time);
}

// void getTime(DataTime* t, char* time_string) {
//   strptime(time_string, "%y-%m-%d %H:%M:%S", t);
// }

char printWeekDay(DataTime* DT) {
  printf("Week day:  %d\n",DT->tm_wday);
  return (char)(DT->tm_wday + 48);
}

DataTime* after(char* time_string) {
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

DataTime* before(char* time_string) {
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

void getTimer(Timer* t_time, const char* string) {
  char *pstring;
  char pstring2[22];

  strncpy(pstring2, string, 2);
  pstring2[2] = '\0';
  t_time->dd = atoi(pstring2);

  pstring = strchr(string, ' ') + 1;
  strncpy(pstring2, pstring, 2);
  t_time->hh = atoi(pstring2);

  pstring += 3;
  strncpy(pstring2, pstring, 2);
  t_time->min = atoi(pstring2);

  pstring += 3;
  strncpy(pstring2, pstring, 2);
  t_time->sec = atoi(pstring2);

  pstring += 3;
  strncpy(pstring2, pstring, 9);
  pstring2[9] = '\0';
  t_time->nano = atoi(pstring2);
}

void addTm(Timer* t1, const Timer* t2) {
  long long temp;

  temp = t1->nano + t2->nano;
  t1->nano = temp % 1000000000;
  temp = t1->sec + t2->sec + temp / 1000000000;
  t1->sec = temp % 60;
  temp = t1->min + t2->min + temp / 60;
  t1->min = temp % 60;
  temp = t1->hh + t2->hh + temp / 60;
  t1->hh = temp % 24;
  t1->dd = t1->dd + t2->dd + temp / 24;
}

void minusTm(Timer* t1, const Timer* t2) {
  long long temp;
  int sign = 1;
  const int n = 1000000000;
  const int d = 24 * 60 * 60;

  long t1_s = t1->sec + t1->min * 60 + t1->hh * 60 * 60;
  long t2_s = t2->sec + t2->min * 60 + t2->hh * 60 * 60;

  if (t2->dd > t1->dd) {
    sign = -1;
  } else if (t2->dd == t1->dd) {
    if (t2_s > t1_s) {
      sign = -1;
    } else if (t2_s == t1_s && t2->nano > t1->nano) {
      sign = -1;
    }
  }

  temp = sign * (t1->nano - t2->nano) + n;
  t1->nano = sign * (temp % n);
  temp = sign * (t1_s - t2_s) + d - 1 + temp / n;
  t1_s = temp % d;
  t1->dd = sign * (sign * (t1->dd - t2->dd) - 1 + temp / d);

  t1->sec = sign * (t1_s % 60);
  t1_s = t1_s / 60;
  t1->min = sign * (t1_s % 60);
  t1_s = t1_s / 60;
  t1->hh = sign * t1_s;
}

void showTimer(const Timer* t) {
  printf("%lld %02d:%02d:%02d:%d\n", t->dd, t->hh, t->min, t->sec, t->nano);
}

void plusTimer(DataTime * time_point, const Timer * t) {
  time_point->tm_mday += t->dd;
  time_point->tm_hour += t->hh;
  time_point->tm_min += t->min;
  time_point->tm_sec += t->sec;
  mktime(time_point); //normalize result
}

void startTime(struct timespec *mt) {
  clock_gettime(CLOCK_REALTIME, mt);
}

void stopTime(struct timespec *mt) {
  struct timespec mt2;
  clock_gettime (CLOCK_REALTIME, &mt2);
  long long delta;
  delta = 1000000000*(mt2.tv_sec - mt->tv_sec)+(mt2.tv_nsec - mt->tv_nsec);
  printf("Time used: %lld ns\n", delta);
}
