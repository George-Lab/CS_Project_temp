all: timer ./TEST/testing_func_printWeekDay/printWeekDay ./TEST/testing_func_getTimer/getTimer

timer: timer.c ./libraries/libtimer.a
	gcc timer.c -L./libraries -ltimer -o timer

./libraries/libtimer.a: ./libraries/timer_lib.h ./libraries/timer_lib.o
	ar -rcs ./libraries/libtimer.a ./libraries/timer_lib.o

./libraries/timer_lib.o: ./libraries/timer_lib.c
	gcc -c -Wall -Werror -Wextra ./libraries/timer_lib.c -o ./libraries/timer_lib.o

./TEST/testing_func_printWeekDay/printWeekDay: ./TEST/testing_func_printWeekDay/printWeekDay.c ./libraries/libtimer.a
	gcc ./TEST/testing_func_printWeekDay/printWeekDay.c -L./libraries -ltimer -o ./TEST/testing_func_printWeekDay/printWeekDay

./TEST/testing_func_getTimer/getTimer: ./TEST/testing_func_getTimer/getTimer.c ./libraries/libtimer.a
	gcc ./TEST/testing_func_getTimer/getTimer.c -L./libraries -ltimer -o ./TEST/testing_func_getTimer/getTimer