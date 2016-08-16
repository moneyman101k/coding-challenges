#!/usr/bin/python

def largest_prime_factor(n):
	if n < 2:
		return 0
	number = n
	i = 2
	largest_valid = 0
	while i <= number:
		if number % i == 0:
			number /= i
			largest_valid = i
			continue
		i = i + 1
	return largest_valid

answer = largest_prime_factor(600851475143)
print "answer is: " + str(answer)