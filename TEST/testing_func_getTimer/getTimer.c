#define __USE_XOPEN // needed for strptime
#define _GNU_SOURCE // needed for strptime
#include <stdio.h> //Для printf
#include <stdlib.h>
#include <time.h>  //Для clock_gettime
#include <string.h>
#include "../../libraries/timer_lib.h"

int main() {
  Timer t1;

  char test_string[22];
  int test_string_size = 22;
  fgets(test_string, test_string_size, stdin);

  getTimer(&t1, test_string);
  showTimer(&t1);

  return 0;
}