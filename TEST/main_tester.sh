#!/bin/bash
echo "Testing the program"

source ./testing_func_printWeekDay/tester.sh ./testing_func_printWeekDay/printWeekDay ./testing_func_printWeekDay/tests/
echo "-----"

source ./testing_func_getTimer/tester.sh ./testing_func_getTimer/getTimer ./testing_func_getTimer/tests/
echo "-----"

source ./testing_func_addTm/tester.sh ./testing_func_addTm/addTm ./testing_func_addTm/tests
echo "-----"

source ./testing_func_minusTm/tester.sh ./testing_func_minusTm/minusTm ./testing_func_minusTm/tests
echo "-----"

source ./testing_func_plusTimer/tester.sh ./testing_func_plusTimer/plusTimer ./testing_func_plusTimer/tests