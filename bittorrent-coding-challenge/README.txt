Program:

One C++ file called "Monkey.cpp". There should only be one print statement as output - which gives the solution.


Running the Program:

	g++ Monkey.cpp
	./a.out


Problem:

There is a monkey which can walk around on a planar grid. The monkey can move one space at a time left, right, up or down. That is, from (x, y) the monkey can go to (x+1, y), (x-1, y), (x, y+1), and (x, y-1). Points where the sum of the digits of the absolute value of the x coordinate plus the sum of the digits of the absolute value of the y coordinate are lesser than or equal to 19 are accessible to the monkey. For example, the point (59, 79) is inaccessible because 5 + 9 + 7 + 9 = 30, which is greater than 19. Another example: the point (-5, -7) is accessible because abs(-5) + abs(-7) = 5 + 7 = 12, which is less than 19. How many points can the monkey access if it starts at (0, 0), including (0, 0) itself?


Solution:

The number of accessible coordinates to the monkey is 102485.


Explanation of Program:

Utilizes recursion in order to perform a traversal on the coordinate system extending out from (0, 0) based on adjacent accessible coordinates of (x+1, y), (x-1, y), (x, y+1), and (x, y-1) from a given current coordinate of (x, y). The basic idea is to perform a check on the current coordinate - to see if its sum of digits is less than or equal to 19 or not. This sum is calculated using the modulo operator to add each of the digits to the sum. For a coordinate with negative value(s), the value(s) is converted to its absolute value before the sum calculation - while maintaining the actual coordinate value.
Following the sum calculation, it is put through the sum checker (to check for coordinate accessibility) - if the sum is less than or equal to 19 and it has not already been accessed (not in a global set), then it will be added to the global set and the accessible coordinate count will be incremented by 1. 
If the corresponding coordinate has already been accessed, then it will already be in a global set of coordinate pairs - causing a return on that recursive call with no further traversal. 
If the corresponding coordinate is inaccessible (sum greater than 19), then it will be returned on that recursive call with no further traversal.
Once the initial function call in main runs to completion, the set will be filled with all of the possible accessible coordinates. The function's return value can be returned - which represents the number of accessible coordinates for the monkey - the same as the size of the set.