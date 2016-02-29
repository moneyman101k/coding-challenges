#include <iostream>
#include <stdlib.h>
#include <set>

using namespace std;


// Set and Function Declarations (Set to Be Used Globally)
set< pair<int, int> > coords;
int monkeyCoordinate(int x, int y);
int absoluteDigitSumCoordinate(int x, int y);


// Main Function to Make Inital Call to Recursive Function
int main()
{
	
	// Function Returns Number of Valid Monkey Coordinates
	int count = monkeyCoordinate(0, 0);

	// STDOUT Output for the Answer
	cout << "Number of Accessible Monkey Coordinates = " << count << endl;

	return 0;
}


// Recursive Function to Determine if Current Monkey Coordinate is Valid or not
// Makes Recursive Call on 4 Adjacent Coordinates if a New, Valid Coordinate
int monkeyCoordinate(int x, int y){

	// Check the Sum to See if it Represents a Valid Coordinate
	if(absoluteDigitSumCoordinate(x, y) <= 19){

		// Check to See if the Valid Coordinate is Already in the Set, By Checking on the Coordinate Pair
		if(coords.find(make_pair(x, y)) != coords.end()){
			return 0;
		}
		
		// If the Valid Coordinate is not Already in the Set, Add it to the Set
		coords.insert(make_pair(x, y));

		// Add 1 to the Number of Valid Coordinates, and Make Recursive Calls on the 4 Adjacent Points
		return 1 + monkeyCoordinate(x-1, y) + monkeyCoordinate(x+1, y)
				 + monkeyCoordinate(x, y-1) + monkeyCoordinate(x, y+1);
	}

	// If the Coordinate is Invalid, Don't Do Anything with it
	return 0;

}


// Function to Compute the Sum of the Digits of Coordinates in Absolute Value
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

	// Return the Integer Sum (to be used by Recursive Function)
	return sum;

}

