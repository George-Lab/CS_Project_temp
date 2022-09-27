#define __USE_XOPEN // needed for strptime
#define _GNU_SOURCE // needed for strptime
#include <stdio.h> //Для printf
#include <time.h>  //Для clock_gettime
#include <string.h>
#include "./headers/timer_lib.h"

int main (void)
{  
  printf("Current local time and date: %s", asctime( setCurrentTime() ));

  char test_string[] = "22-04-15 16:35:12";
  printf("Current local time and date: %s", asctime( getTime(test_string) ));

  printWeekDay( setCurrentTime() );
  //printf("%c\n", printWeekDay( setCurrentTime() ));

  char test_string_2[] = "15 01:50:52";
  printf("Current local time and date: %s", asctime( after(test_string_2) ));

  return 0;
}