Program:

One C++ file called "Monkey.cpp"


Running the Program:

	g++ Monkey.cpp
	./a.out


Problem:

There is a monkey which can walk around on a planar grid. The monkey can move one space at a time left, right, up or down. That is, from (x, y) the monkey can go to (x+1, y), (x-1, y), (x, y+1), and (x, y-1). Points where the sum of the digits of the absolute value of the x coordinate plus the sum of the digits of the absolute value of the y coordinate are lesser than or equal to 19 are accessible to the monkey. For example, the point (59, 79) is inaccessible because 5 + 9 + 7 + 9 = 30, which is greater than 19. Another example: the point (-5, -7) is accessible because abs(-5) + abs(-7) = 5 + 7 = 12, which is less than 19. How many points can the monkey access if it starts at (0, 0), including (0, 0) itself?


Solution:

The number of accessible coordinates to the monkey is 102485.


Explanation of Program:

Utilizes recursion in order to perform a traversal on the coordinate system extending out from (0, 0) based on adjacent accessible coordinates of (x+1, y), (x-1, y), (x, y+1), and (x, y-1) from a given current coordinate of (x, y). The basic idea is to perform a check on the current coordinate - to see if its sum of digits is less than or equal to 19 or not. This sum is calculated using the modulo operator to add each of the digits to the sum. For a coordinate with negative value(s), the value(s) is converted to its absolute value before the sum calculation - while maintaining the actual coordinate value.
Following the sum calculation, it is put through the sum checkers (to check for coordinate accessibility) - if the sum is less than or equal to 19, then the coordinate has already been accessed or it has not. If the corresponding coordinate has already been accessed, then it will already be in a global set of coordinate pairs - causing a return on that recursive call. If the corresponding coordinate hasn't already been accessed, then it will be inserted into the set, and a recursive function call will be made to try to access the 4 adjacent coordinates around it.
If the sum is greater than 19, then the coordinate is not a valid coordinate for the monkey to access. As such, a return will be made on that recursive call - and the coordinates adjacent to it should not be attempted to be accessed.
Once the function completes, the set will be completely filled - with each coordinate pair representing a possible coordinate for the monkey to access. The function's return value can be returned - which represents the number of accessible coordinates for the monkey - which is exactly the same as the size of the set.