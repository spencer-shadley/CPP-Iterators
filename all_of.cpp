#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

namespace spencer {
	template < typename II, typename FN >
	bool all_of(II b, II e, FN fn) {
		while (b != e) {
			if (!fn(*b)) return false;
			b++;
		}
		return true;
	}
}

//void main() {
//	vector<int> x = { 1, 2, 3 };
//	assert(spencer::all_of(x.begin(), x.end(),
//		[] (int x) -> bool { return x < 4; }));
//	x[2] = 4;
//	assert(!spencer::all_of(x.begin(), x.end(),
//		[] (int x) -> bool { return x < 4; }));
//	assert(!spencer::all_of(x.begin(), x.end(),
//		[] (int x) -> bool { return x == 1 || x == 4 || x == 3; }));
//}
