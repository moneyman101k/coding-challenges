#!/usr/bin/python

def multiples( n ):
	print n
	sum = 0
	for i in range(0, n):
		if i % 3 == 0:
			sum += i
		if i % 3 != 0:
			if i % 5 == 0:
				sum += i
	return sum

answer = multiples(1000)
print "answer is: " + str(answer)