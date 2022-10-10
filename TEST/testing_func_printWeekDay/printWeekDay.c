#define __USE_XOPEN // needed for strptime
#define _GNU_SOURCE // needed for strptime
#include <stdio.h> //Для printf
#include <stdlib.h>
#include <time.h>  //Для clock_gettime
#include <string.h>
#include "../../libraries/timer_lib.h"

int main() {
  DataTime dtime;
  char test_string[18];
  int test_string_size = 18;
  fgets(test_string, test_string_size, stdin);
  strptime(test_string, "%y-%m-%d %H:%M:%S", &dtime);
  
  printWeekDay(&dtime);

  return 0;
}