#!/usr/bin/python

def largest_palindrome(a, b):
	flag = 1
	loop_a = a
	loop_b = b
	answer = []
	while loop_a >= 100:
		loop_b = b
		while loop_b >= 100:
			product = loop_a * loop_b
			if str(product) == str(product)[::-1]:
				answer.append(product)
			loop_b = loop_b - 1
		loop_a = loop_a - 1
	answer.sort()
	answer.reverse()
	return answer[0]

answer = largest_palindrome(999, 999)
print "answer is: " + str(answer)