#include <iostream>
#include <cassert>
using namespace std;

static bool debug = true;
static bool db_sqrt = true;

// calculate square root
int sqrt(int num) {
	if (debug && db_sqrt) cout << num << endl;
	assert(num >= 0);
	if (num == 0 || num == 1) return num;
	int low_bound = 0;
	int high_bound = num;
	while (low_bound <= high_bound) {

		// calculate square
		int square = (high_bound - low_bound) / 2;
		square *= square;
		
		// check for binary movement
		if (square == num)	return (high_bound - low_bound) / 2;
		if (square > num)	high_bound = square - 1;
		else				low_bound  = square + 1;
		
		// error checking
		if (debug && db_sqrt) cout << square << " " << low_bound << " " << high_bound << endl;
	}
	return num;
}

bool is_palindrome(string s) {
	assert(&s != nullptr);

	int beg = 0;
	int end = s.size() - 1;

	while (beg != end / 2)
		if (s[beg++] != s[end--]) return false;
	return true;
}

void main() {

	// sqrt
	/*assert(sqrt(4) == 2);
	assert(sqrt(64) == 8);
	assert(sqrt(36) == 6);
	assert(sqrt(0) == 0);
	assert(sqrt(1) == 1);*/

	// palindrome
	string s = "racessqwercar";
	assert(!is_palindrome(s));
	s = "racecar";
	assert(is_palindrome(s));

	// array practice
	int x[] = { 1, 2, 3, 4 };
	*(x+1) = 9;
	x[3] = 7;
	assert(x[1] == 9);
	assert(x[3] == 7);
}