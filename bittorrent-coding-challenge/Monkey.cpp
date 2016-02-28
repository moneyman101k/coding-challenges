#include <iostream>
#include <stdlib.h>
#include <set>

using namespace std;


int absoluteDigitSumCoordinate(int x, int y){

	// Variable for the Sum of Digits for Current Coordinate Pair
	int sum = 0;

	// Take the Absolute Value of the Coordinate Pair
	int check_x = abs(x);
	int check_y = abs(y);

	// Add up the Digits of the X-Coordinate to Sum (Digit by Digit)
	while(check_x != 0){
		// Add Current Digit - Using Modulo By 10
		sum += (check_x % 10);
		// Move to the Next Digit
		check_x /= 10;
	}

	// Add up the Digits of the Y-Coordinate to Sum (Digit by Digit)
	while(check_y != 0){
		// Add Current Digit - Using Modulo By 10
		sum += (check_y % 10);
		// Move to the Next Digit
		check_y /= 10;
	}

	// Return the Integer Sum
	return sum;

}


int monkeyCoordinate(int x, int y, set<pair <int, int> > &coords){

	// Check the Sum to See if it Represents a Valid Coordinate
	if(absoluteDigitSumCoordinate(x, y) <= 19){

		// Check to See if the Valid Coordinate is Already in the Set, By Checking on the Coordinate Pair
		if(coords.find(make_pair(x, y)) != coords.end()){
			return 0;
		}
		
		// If the Valid Coordinate is not Already in the Set, Add it to the Set
		coords.insert(make_pair(x, y));

		// Add 1 to the Number of Valid Coordinates, and Make Recursive Calls on the 4 Adjacent Points
		return 1 + monkeyCoordinate(x-1, y, coords) + monkeyCoordinate(x+1, y, coords)
				 + monkeyCoordinate(x, y-1, coords) + monkeyCoordinate(x, y+1, coords);
	}

	// If the Coordinate is Invalid, Don't Do Anything with it
	return 0;

}


int main()
{
	// Set Used to Fill in with Coordinates
	set< pair<int, int> > coords;

	// Pass the Coordinate Set into the Function - Accessed within Function by Reference
	monkeyCoordinate(0, 0, coords);

	// STDOUT Output for the Answer
	cout << "Total Valid Monkey Coordinates = " << coords.size() << endl;

	return 0;
}