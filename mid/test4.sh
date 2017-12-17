#!/bin/bash

i=1
j=1
while [ $i -le 9 ]
do
	while [ $j -le 9 ]
	do
		echo "$i x $j = $((i*j))"
		j=$(($j+1))
	done
	i=$(($i+1))
	j=0
done
