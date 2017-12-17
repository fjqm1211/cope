#! /bin/bash

comnumber=0
comnumber=$(( $RANDOM % 101 ))
judge=1

while [ $judge == 1 ]
do
  read mynumber

  if [ $mynumber -gt $comnumber ]; then
   echo "$mynumber down"
  elif [ $mynumber -lt $comnumber ]; then
   echo "$mynumber up"
  elif [ $mynumber -eq $comnumber ]; then
   echo "correct you win"
   judge=0
  fi
done
