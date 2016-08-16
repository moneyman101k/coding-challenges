#!/usr/bin/python

def ten_thousand_first_prime(n):
	primes = []
	count = 0
	flag = 0
	curr_num = 2
	while count < n:
		flag = 0
		for i in range(0, len(primes)):
			if curr_num % primes[i] == 0:
				flag = 1
				break
		if flag == 0:
			primes.append(curr_num)
			count += 1
		curr_num += 1
	return curr_num-1
	

answer = ten_thousand_first_prime(10001)
print "answer is: " + str(answer)