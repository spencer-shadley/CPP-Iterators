#include <iostream>
#include <functional>
#include <numeric>
#include <vector>
using namespace std;

typedef int (*BF) (int, double);
using BF1 = int(*) (int, double);
using BF2 = function<int (int, int)>;

BF2 add() {
	return [](int i, int j) -> int {return i + j; };
}
//void main() {
//	vector<int> x = { 1, 2, 3 };
//	int accumulated = accumulate(x.begin(), x.end(), 0, add);
//	cout << accumulated << endl;
//}