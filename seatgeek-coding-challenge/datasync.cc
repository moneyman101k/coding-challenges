// SeatGeek Backend Challenge 2 - Data Center Recovery
// Name: Maneesh Karipineni
// Date: 4/9/16

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){ 

  int num_centers;
  int i;
  char data_centers[1000];

  cin.getline(data_centers, 1000);
  num_centers = atoi(data_centers);

  char data_sets_in_center[1000];
  char *each_data_set;
  vector<set<int> > all_data_centers;

  for (i = 1; i <= num_centers; ++i) {
    cin.getline(data_sets_in_center, 1000);
    set<int> new_data_center;
    each_data_set = strtok(data_sets_in_center, " ");
    while (each_data_set != NULL) {
      new_data_center.insert(atoi(each_data_set));
      each_data_set = strtok(NULL, " ");
    }
    all_data_centers.push_back(new_data_center);
  }

  vector<set<int> >::iterator origin_data_center;
  vector<set<int> >::iterator destination_data_center;
  set<int>::iterator data_set;

  for (origin_data_center = all_data_centers.begin();
       origin_data_center != all_data_centers.end();
       ++origin_data_center) {
    for (data_set = origin_data_center->begin(); 
         data_set != origin_data_center->end();
         ++data_set) {
      for (destination_data_center = all_data_centers.begin();
           destination_data_center != all_data_centers.end();
           ++destination_data_center) {
        if (destination_data_center->find(*data_set) == 
            destination_data_center->end()) {
          destination_data_center->insert(*data_set);
          cout << *data_set;
          cout << " " << distance(all_data_centers.begin(), 
                                  origin_data_center+1);
          cout << " " << distance(all_data_centers.begin(), 
                                  destination_data_center+1);
          cout << endl;
        }
      }
    }
  }
  
  cout << "done" << endl;
  return 0;
}