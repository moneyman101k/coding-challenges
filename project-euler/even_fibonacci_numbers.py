#!/usr/bin/python

def even_fib(n):
	f1 = 1
	f2 = 1
	if n < 2:
		return 0
	curr = 0
	answer = 0
	while curr <= n:
		curr = f1 + f2
		if curr % 2 == 0:
			answer += curr
		f1 = f2
		f2 = curr
	return answer

answer = even_fib(4000000)
print "answer is: " + str(answer)