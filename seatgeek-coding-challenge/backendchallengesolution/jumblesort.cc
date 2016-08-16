// SeatGeek Backend Challenge 1 - Jumble Sort
// Name: Maneesh Karipineni
// Date: 4/9/16

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){

  int argi = 0;
  int firstChar = 0;
  int type_num = 0;
  int type_str = 1;

  vector<int> type_flags;
  vector<int> nums;
  vector<string> strs;

  vector<int>::iterator type_flags_it = type_flags.begin();
  vector<int>::iterator nums_it = nums.begin();
  vector<string>::iterator strs_it = strs.begin();

  for (argi = 1; argi < argc; ++argi) {
    firstChar = argv[argi][0];
    if (firstChar == 45 || (firstChar >= 48 && firstChar <= 57)) {
      type_flags.push_back(type_num);
      nums.push_back(atoi(argv[argi]));
    } else if ((firstChar >= 97) && (firstChar <= 122)) {
      type_flags.push_back(type_str);
      strs.push_back(argv[argi]);
    } else {
      cout << "Invalid input";
    }
  }

  sort(nums.begin(), nums.end());
  sort(strs.begin(), strs.end());

  for (type_flags_it = type_flags.begin(); type_flags_it != type_flags.end();
       ++type_flags_it) {
    if (*type_flags_it == type_num) {
      cout << nums.front() << " ";
      nums.erase(nums.begin());
    } else {
      cout << strs.front() << " ";
      strs.erase(strs.begin());
    }
  }

  cout << endl;
  return 0;
}