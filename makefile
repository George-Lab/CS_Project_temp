all: timer ./TEST/testing_func_printWeekDay/printWeekDay ./TEST/testing_func_getTimer/getTimer ./TEST/testing_func_addTm/addTm ./TEST/testing_func_minusTm/minusTm ./TEST/testing_func_plusTimer/plusTimer

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

./TEST/testing_func_addTm/addTm: ./TEST/testing_func_addTm/addTm.c ./libraries/libtimer.a
	gcc ./TEST/testing_func_addTm/addTm.c -L./libraries -ltimer -o ./TEST/testing_func_addTm/addTm

./TEST/testing_func_minusTm/minusTm: ./TEST/testing_func_minusTm/minusTm.c ./libraries/libtimer.a
	gcc ./TEST/testing_func_minusTm/minusTm.c -L./libraries -ltimer -o ./TEST/testing_func_minusTm/minusTm

./TEST/testing_func_plusTimer/plusTimer: ./TEST/testing_func_plusTimer/plusTimer.c ./libraries/libtimer.a
	gcc ./TEST/testing_func_plusTimer/plusTimer.c -L./libraries -ltimer -o ./TEST/testing_func_plusTimer/plusTimer