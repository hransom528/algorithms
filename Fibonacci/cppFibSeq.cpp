// Fibonacci Sequence solver in C++
// Harris Ransom

/** Includes **/
#include <iostream>
using namespace std;

/** Defines **/
#define NUM_FIBS 25

/** Functions **/
int fibSeq(int pos) {
	if (pos == 0 || pos == 1)
		return pos;
	return fibSeq(pos - 2) + fibSeq(pos - 1);
}

/** MAIN **/
int main(int argc, char *argv[]) {
    cout << "Fibonacci Numbers (1 - " << NUM_FIBS << "): " << endl;
    for (int i = 1; i <= NUM_FIBS; i++) {
	if (i <= 9) {
		printf("\t%d  - %d\n", i, fibSeq(i));
	}
	else {
		printf("\t%d - %d\n", i, fibSeq(i));
	}
    }
    return 0;
}
