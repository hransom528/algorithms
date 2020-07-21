// Implementation of built in Linked List in C++
// Harris Ransom

/** Includes **/
#include <algorithm>	// std::find
#include <forward_list>	// std::forward_list
#include <iostream>

using namespace std;

/** Functions **/
// Prints out given int list
void printList(forward_list<int> *ll) {
	for (auto i = ll->begin(); i != ll->end(); i++)
		cout << *i << '\n' << endl;
	cout << "----\n" << endl;
}

// Find item with given value in list
int findItem(forward_list<int> *ll, int item) {
	for (auto i = ll->begin(); i != ll->end(); i++) {
		if (*i == item) {
			printf("Found node with value %d\n", *i);
			return *i;
		}
	}
	cout << "Item not found!" << endl;
	return (int) NULL;
}

/** MAIN **/
int main() {
	forward_list<int> nums; // Built-in data structure

	// Appends 0-24 to head
	for (int i = 0; i < 24; i++) {
		nums.push_front(i);
	}
	printList(&nums);

	// Finds node of value 13
	findItem(&nums, 13);

	// Inserts 75 after 13
	auto it = find(nums.begin(), nums.end(), 13);
	if (it != nums.end()){
		cout << "Inserted 75 sucessfully" << endl;
		nums.insert_after(it, 75);
	}
	else {
		cout << "Error with insertion of 75 after 13!" << endl;
	}
	printList(&nums);

	return 0;
}
