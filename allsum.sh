#! /bin/bash

sum(){
	total=0
	for i in $*;
	do
		total=$((total + $i))
	done
	echo $total
}

read numbers
echo "Sum: $(sum $numbers)"
