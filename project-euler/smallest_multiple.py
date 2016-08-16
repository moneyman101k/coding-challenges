#!/usr/bin/python

def smallest_multiple(n):
	needed_factors = []
	for i in range(1, n):
		curr = i
		for j in range(len(needed_factors)):
			if curr % needed_factors[j] == 0:
				curr /= needed_factors[j]
		if curr != 1:
			needed_factors.append(curr)
	answer = 1
	for k in range(len(needed_factors)):
		answer *= needed_factors[k]
	return answer

answer = smallest_multiple(20)
print "answer is: " + str(answer)