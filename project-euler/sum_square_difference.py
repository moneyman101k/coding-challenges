#!/usr/bin/python

def sum_square_difference(n):

	a = n * (n+1) * (2 * n + 1) / 6
	b = (n * (1 + 100) / 2) * (n * (1 + 100) / 2)
	return b - a

answer = sum_square_difference(100)
print "answer is: " + str(answer)