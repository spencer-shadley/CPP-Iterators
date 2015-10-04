#include <iostream>
#include <vector>
#include <list>
using namespace std;

namespace spencer {
	template < typename II, typename OI >
	OI copy(II b, II e, OI result) {
		while (b != e) {
			*result = *b;
			result++;
			b++;
		}
		return result;
	}
}

int main()
{
	vector<int> x = { 1, 2, 3 };
	list<int> y(3);

	spencer::copy(x.begin(), x.end(), y.begin());

	for (auto& x : y) {
		cout << x << endl;
	}

	return 0;
}