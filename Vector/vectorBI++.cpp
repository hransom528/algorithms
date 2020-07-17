// Implementation of Vector data structure in C++ with std::vector
// Harris Ransom

#include <iostream>
#include <vector>

using namespace std;

// Outputs given int vector's contents
void printVector(vector<int> *v) {
	for (int i = 0; i < v->size(); i++) {
		cout << v->at(i) << endl;
	}
	cout << "----" << endl;
}

int main() {
	vector<int> nums;	// Built-in data structure
	
	// Adds 5 ints to vector
	for (int i = 0; i < 5; i++) {
		nums.push_back(i); // Appends i to end of list
		
	}
	printVector(&nums);
	
	// Removes 2nd element via begin iterator
	nums.erase(nums.begin() + 1); 
	printVector(&nums);
	
	// Inserts 1 at index 3
	nums.insert(nums.begin() + 3, 1);
	printVector(&nums);
	
	// Pops the last element and inserts it at index 1
	nums.insert(nums.begin() + 1, nums.back());
	nums.pop_back();
	printVector(&nums);
	
	// Clears vector
	nums.clear();
	printVector(&nums);
	
	return 0;
}
