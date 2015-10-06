#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool even(int num) {
	return num % 2 == 0;
}

//int main() {
//
//	//regular function
//	vector<int> x = { 1, 2, 3 };
//	bool result = all_of(x.begin(), x.end(), &even);
//	cout << result << endl;
//
//	int capture_me = 2;
//	all_of(x.begin(), x.end(), [capture_me] (int curr) -> bool {return curr % capture_me == 0; });
//
//	result = all_of(x.begin(), x.end(), &even);
//	cout << result << endl;
//}