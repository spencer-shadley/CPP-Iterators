#include <iostream>
using namespace std;

template <typename T>
class Range_Iterator {
private:
	T value;
public:
	Range_Iterator(const T& passed) : value(passed){}

	bool operator==(const Range_Iterator& rhs) const {
		return value == rhs.value;
	}

	bool operator!=(const Range_Iterator& rhs) const {
		return value != rhs.value;
	}

	const T& operator*() const {
		return value;
	}

	Range_Iterator& operator++() {
		++value;
		return *this;
	}

	Range_Iterator operator++(int) {
		Range_Iterator copy = *this;
		value++;
		return copy;
	}
};

template <typename T>
class stack {
private:
	vector<T> v;
public:
	typedef Range_Iterator<T*> iterator;

	stack() : v() {}
	stack(vector<T> v_given) : v(v_given) {}

	void push(const T& value) {
		v.push_back(value);
	}

	T& pop() {
		assert(v.size() > 0);
		T popped = v[v.size() - 1];
		v.pop_back();
		return popped;
	}

	const T& peek() const {
		assert(v.size() > 0);
		return v[v.size() - 1];
	}

	int size() {
		return v.size();
	}

	// stack shouldn't support this
	// just testing more op overloading
	T& operator[](int index) {
		return v[index];
	}

	iterator begin() {
		iterator it = &v;
		return it;
	}

	iterator end() {
		iterator it = &v + v.size();
		return it;
	}
};


void main() {
	Range_Iterator<int> r = 3;
	
	stack<int> st = stack<int>();
	st.push(3);

	for (const auto &i : st) {
		cout << *i << " ";
	}
}