 
// Implementation of the built in Standard Library sorting algorithm
// Harris Ransom

/** Includes **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/** Functions **/
// Outputs array formatted
void printArr(vector<int> v) {
    cout << "Size: " << v.size() << endl;
    for (int i : v)
        cout << i << endl;
}

/** MAIN **/
int main() {
    vector<int> nums = {3, 1, 8, 5, 2, 7, 4, 10, 6, 9};
    cout << "Initial vector: " << endl;
    printArr(nums);
    
    sort(nums.begin(), nums.end());
    cout << "\nSorted vector: " << endl;
    printArr(nums);
    return 0;
}
