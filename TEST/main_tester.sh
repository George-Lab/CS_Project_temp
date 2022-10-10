#!/bin/bash
echo "Testing the program"

source ./testing_func_printWeekDay/tester.sh ./testing_func_printWeekDay/printWeekDay ./testing_func_printWeekDay/tests/
echo "-----"

source ./testing_func_getTimer/tester.sh ./testing_func_getTimer/getTimer ./testing_func_getTimer/tests/