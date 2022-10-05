#define __USE_XOPEN // needed for strptime
#define _GNU_SOURCE // needed for strptime
#include <stdio.h> //Для printf
#include <stdlib.h>
#include <time.h>  //Для clock_gettime
#include <string.h>
#include "./libraries/timer_lib.h"

int main (void)
{
  struct timespec mt;
  startTime(&mt);
  DataTime dtime;
  setCurrentTime(&dtime);
  printf("Current local time and date: %s", asctime( &dtime ));

  char test_string[] = "22-04-15 16:35:12";
  strptime(test_string, "%y-%m-%d %H:%M:%S", &dtime);
  printf("Current local time and date: %s", asctime( &dtime ));

  printWeekDay( &dtime );


  char test_string_2[] = "12 05:38:22";
  printf("Local time and date after dd hh::mm::ss -> %s: %s", test_string_2, asctime( after(test_string_2) ));
  printf("Local time and date dd hh::mm::ss before -> %s: %s", test_string_2, asctime( before(test_string_2) ));

  ////////// Timer section
  Timer t1;
  Timer t2;

  char test_string_3[] = "01 21:27:36:247345000";
  getTimer(&t1, test_string_3);
  printf("Timer 1: ");
  showTimer(&t1);

  // char test_string_4[] = "01 02:03:05:900";
  char test_string_4[] = "19 18:47:54:968317987";
  getTimer(&t2, test_string_4);
  printf("Timer 2: ");
  showTimer(&t2);

  addTm(&t1, &t2);
  printf("Timer 1 + Timer 2 : ");
  showTimer(&t1);

  minusTm(&t1, &t2);
  printf("Timer 1 - Timer 2 : ");
  showTimer(&t1);

  /////////////////
  plusTimer(&dtime, &t1);
  printf("DataTime + Timer 1 : %s", asctime( &dtime ));

  stopTime(&mt);

  return 0;
}