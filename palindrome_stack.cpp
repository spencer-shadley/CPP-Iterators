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

	void push(const T& value) {
		v.push_back(value);
	}

	T& pop() {
		assert(v.size() > 0);
		T popped = v[v.size()-1];
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

	T& operator[](int index) {
		return v[index];
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

	stack<int> st = stack<int>();
	st.push(3);
	int temp = 4;
	st.push(temp);
	assert(st.peek() == 4);
	assert(st.pop() == 4);
	assert(st.pop() == 3);
	st.push(42);
	assert(st.pop() == 42);
}