#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

namespace my {

	// find the given value
	template <typename II, typename V>
	inline II find(II b, II e, V value) {
		while (b != e) {
			if (*b == value)
				return b;
			b++;
		}
		assert(false);
	}

	// check if two containers are equal
	template <typename II, typename II2>
	inline bool equal(II b, II e, II2 b2) {
		while (b != e)
			if (*b++ != *b2++)
				return false;
		return true;
	}

	// copy from one container to another
	template<typename II, typename OI>
	inline OI copy(II b, II e, OI b2) {
		while (b != e) *b2++ = *b++;
		return b2;
	}

	// fill with given value
	template<typename FI, typename V>
	inline void fill(FI b, FI e, V value) {
		while (b != e) *b++ = value;
	}

	// reverse given collection (avoiding the useful swap algorithm)
	template<typename BI>
	inline void reverse_no_swap(BI b, BI e) {
		while ((b != e) && (b != --e)) {
			auto temp = *b;
			*b++ = *e;
			*e = temp;
		}
	}

	// reverse given collection (with a for loop)
	template<typename BI>
	inline void reverse_for(BI b, BI e) {
		int size = (e - b);
		for (int i = 0; i < size / 2; i++)
			swap(b++, e--);
	}

	// reverse given collection (cleanest)
	template<typename BI>
	void reverse(BI b, BI e) {
		while ((b != e) && (b != --e))
			swap(*b++, *e);
	}
}

void main() {
	vector<int>		x = { 1, 2, 3 };
	vector<int>		y = { 1, 2, 3 };
	vector<double>	z = { 1.1, 1.2, 1.3 };
	
	// test find
	assert(*my::find(x.begin(), x.end(), 2) == 2);

	// test equal
	assert(my::equal(x.begin(), x.end(), y.begin()));
	assert(!my::equal(x.begin(), x.end(), z.begin()));

	// test copy
	y[0] = 17;
	my::copy(x.begin(), x.end(), y.begin());
	assert(equal(x.begin(), x.end(), y.begin()));

	// test fill
	my::fill(x.begin(), x.end(), 9);
	for (int temp : x)
		assert(temp == 9);

	// test reverse
	x = { 1, 2, 3 };
	y = { 3, 2, 1 };
	my::reverse_no_swap(y.begin(), y.end());
	my::reverse(y.begin(), y.end());
	//assert(equal(x.begin(), x.end(), y.begin()));
}