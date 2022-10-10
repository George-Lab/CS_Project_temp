#!/bin/bash

# Checking number of arguments
if [ $# -ne 2 ]; then
	echo "Wrong number of arguments"
	exit 1
fi

# Checking if the first argument is a file
if [ -e $"$1" ]; then
	if [ ! -f $"$1" ]; then
		echo "\"$1\" is not a file"
		exit 1
	fi
else
	echo "File \"$1\" doesn't exist"
	exit 1
fi

# Checking if the second argument is a directory
if [ -e $"$2" ]; then
	if [ ! -d $"$2" ]; then
		echo "\"$2\" is not a directory"
		exit 1
	fi
else 
	echo "Directory \"$2\" doesn't exist"
	exit 1
fi

echo "Testing function minusTm"

# Looping through all files in a directory
# And testing c program
counter=1
num_ok_tests=0
FILES="$2"
for file in "$FILES/test_data/"* ;
do
	output=$("$1" < "$file")

	echo -n "Test $counter: "
	if [[ $(< "$FILES""/test_results/test_res"$counter".txt") == "$output" ]]; then
		echo OK
		((num_ok_tests++))
	else 
		echo FAIL
	fi

	((counter++))
done
((counter--))

echo "Passed $num_ok_tests out of $counter tests"
