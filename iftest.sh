#! /bin/bash

dirname=$(ls)
echo $dirname
for n in $dirname;
do
	if [ -x  $n ];then
		echo "$n is available"
	else echo "$n is not available"
	fi
done
