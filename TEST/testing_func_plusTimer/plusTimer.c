#define __USE_XOPEN // needed for strptime
#define _GNU_SOURCE // needed for strptime
#include <stdio.h> //Для printf
#include <stdlib.h>
#include <time.h>  //Для clock_gettime
#include <string.h>
#include "../../libraries/timer_lib.h"

int main() {
  DataTime dtime;
  Timer t1;

  char test_string_1[23], test_string_2[22]; 
  int test_string_1_size = 23, test_string_2_size = 18;
  fgets(test_string_1, test_string_1_size, stdin);
  test_string_1[22] = '\0';
  fgets(test_string_2, test_string_2_size, stdin);

  getTimer(&t1, test_string_1);
  strptime(test_string_2, "%y-%m-%d %H:%M:%S", &dtime);

  showTimer(&t1);
   printf("%s", asctime( &dtime ));


  plusTimer(&dtime, &t1);
  printf("%s", asctime( &dtime ));

  return 0;
}