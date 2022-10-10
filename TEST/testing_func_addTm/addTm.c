#define __USE_XOPEN // needed for strptime
#define _GNU_SOURCE // needed for strptime
#include <stdio.h> //Для printf
#include <stdlib.h>
#include <time.h>  //Для clock_gettime
#include <string.h>
#include "../../libraries/timer_lib.h"

int main() {
  Timer t1;
  Timer t2;

  char test_string_1[23], test_string_2[22]; 
  int test_string_size = 23;
  fgets(test_string_1, test_string_size, stdin);
  test_string_1[22] = '\0';
  fgets(test_string_2, test_string_size, stdin);

  getTimer(&t1, test_string_1);
  getTimer(&t2, test_string_2);

  addTm(&t1, &t2);
  showTimer(&t1);

  return 0;

}