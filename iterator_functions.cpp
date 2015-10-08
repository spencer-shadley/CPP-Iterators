#include <iostream>
#include <vector>
#include <cassert>
#include <numeric>
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
	inline void reverse(BI b, BI e) {
		while ((b != e) && (b != --e))
			swap(*b++, *e);
	}

	// swap given values
	template<typename T>
	inline void swap(T& a, T& b) {
		a ^= b;
		b ^= a;
		a ^= b;
	}

	// remove 
	template<typename FI, typename T>
	inline FI remove(FI b, FI e, const T& val) {
		FI result;
		while (b != e) {
			if (*b != val) {
				*result = *b;
				++result; ++b;
			} else ++b;
		}
		return result;
	}

	// count
	template<typename II, typename T>
	inline int count(II b, II e, const T& val) {
		int total = 0;
		while (b != e)
			if (*b++ == val) total++;
		return total;
	}

	// all_of
	template<typename II, typename UF>
	inline bool all_of(II b, II e, UF pred) {
		while (b != e)
			if (!pred(*b++)) return false;
		return true;
	}

	// accumulate v1
	template<typename II, typename T>
	inline T accumulate(II b, II e, T init) {
		while (b != e) init += *b++;
		return init;
	}

	// accumulate v2 (function)
	template<typename II, typename T, typename BF>
	inline T accumulate(II b, II e, T init, BF binop) {
		while (b != e) init = binop(init, *b++);
		return init;
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
	for (int temp : x) assert(temp == 9);

	// test reverse
	x = { 1, 2, 3 };
	y = { 3, 2, 1 };
	my::reverse_no_swap(y.begin(), y.end());
	my::reverse(y.begin(), y.end());
	//assert(equal(x.begin(), x.end(), y.begin()));

	// test swap
	int i = 6;
	int j = 9;
	my::swap(i, j);
	assert(j == 6 && i == 9);

	// TODO: remove
	/*x = { 1, 2, 3, 4, 2, 5, 2, 6 };
	y = { 1, 3, 4, 5, 6 };
	my::remove(x.begin(), x.end(), 2);*/
	//for (int i : x)
		//cout << i << endl;
	//assert(equal(x.begin(), x.end(), y.begin()));

	// count
	x = { 1, 1, 1, 2, 3, 4, 1 };
	int count = my::count(x.begin(), x.end(), 1);
	assert(count == 4);

	// all_of
	x = { 2, 4, 6, 8, 10 };
	assert(my::all_of(x.begin(), x.end(), [](int input)->bool {return input % 2 == 0; }));

	// accumluate
	int std_acc = accumulate(x.begin(), x.end(), 2);
	int my_acc = my::accumulate(x.begin(), x.end(), 2);
	assert(my_acc == std_acc);
	std_acc = accumulate(	x.begin(), x.end(), 2, [](int input1, int input2)->int {return input1*input2 + 51 % 33; });
	my_acc = my::accumulate(x.begin(), x.end(), 2, [](int input1, int input2)->int {return input1*input2 + 51 % 33; });
	assert(my_acc == std_acc);
}