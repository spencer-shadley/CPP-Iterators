#include <iostream>
#include <string>
#include <cassert>
#include <vector>
using namespace std;

template <typename T>
class stack {
private:
	vector<T> v;
public:
	stack() : v() {}
	stack(vector<T> v_given) : v(v_given) {}

	// push
	void push(const T& value) {
		v.push_back(value);
	}

	// pop
	T pop() {
		assert(v.size() > 0);
		v.pop_back();
	}

	// peek
	const T& peek() const {
		assert(v.size() > 0);
		return v[v.size() - 1];
	}

	// size
	int size() {
		return v.size();
	}
};

bool is_palindrome(string s) {

	assert(&s != nullptr);

	int beg = 0;
	int end = s.size() - 1;

	while (beg != end) {
		if (s[beg++] != s[end--])
			return false;
	}
	return true;
}

void main() {

	string s = "racessqwercar";
	cout << is_palindrome(s) << endl;



}