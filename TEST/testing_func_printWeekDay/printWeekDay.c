#define __USE_XOPEN // needed for strptime
#define _GNU_SOURCE // needed for strptime
#include <stdio.h> //Для printf
#include <stdlib.h>
#include <time.h>  //Для clock_gettime
#include <string.h>
#include "../../headers/timer_lib.h"

int main() {
  DataTime dtime;
  char *test_string = NULL;
  size_t test_string_size = 11;
  getline(&test_string, &test_string_size, stdin);
  strptime(test_string, "%y-%m-%d %H:%M:%S", &dtime);
  
  printWeekDay(&dtime);

  free(test_string);
  return 0;
}