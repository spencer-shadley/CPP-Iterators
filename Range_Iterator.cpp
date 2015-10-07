#include <iostream>
using namespace std;

template <typename T>
class Range_Iterator {
private:
	T _v;
public:
	Range_Iterator(const T &v) {
		_v = v;
	}

	bool operator == (const Range_Iterator& rhs) const {
		return _v == rhs._v;
	}

	bool operator != (const Range_Iterator& rhs) const {
		return _v != rhs._v;
	}

	const T& operator * () const {
		return _v;
	}

	Range_Iterator operator++() {
		++_v;
		return this;
	}

	Range_Iterator& operator++(int) {
		Range_Iterator x = *this;
		++*this;
		return x;
	}
};

//void main() {
//	Range_Iterator<int> r = 3;
//	int x = *r;
//	x++;
//	cout << x << endl; // x is 4
//}