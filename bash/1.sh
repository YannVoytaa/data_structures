#! /usr/bin/bash

tests=100
g++ -o 1 1.cpp
g++ -o brut brut.cpp
for (( i=0; i<tests; i++ ))
do
	python3 1.py > 1.in
	./1 < 1.in > 1.out
	./brut < 1.in > 2.out
	if [ $(<1.out) -ne $(<2.out) ]
	then
		echo "$i Blad"
		break
	else
		echo "$i OK"
		# $(<1.out) $(<2.out)" 
	fi
done
