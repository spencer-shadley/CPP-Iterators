#include <iostream>
#include <cassert>
using namespace std;

int f(int x) {
	cout << "f - start" << endl;
	if (x == 0) {
		cout << "f - 0" << endl;
		throw 20; // because we can throw whatever we want bro :)
	}
	else cout << "f - !0" << endl;
	cout << "f - end" << endl;;
}

void g(int y) {
	cout << "g - start" << endl;
	if (y == 20) {
		cout << "g - 20" << endl;
		throw 42;
		cout << "g - after throw" << endl;;
	}
	cout << "g - finished";
}

//void main() {
//	cout << "main - about to call f" << endl;
//	try { f(0); }
//	catch (int& e) {
//		cout << "main - caught " << e << endl;
//		cout << "main - about to call g" << endl;
//		try { g(e); }
//		catch (int& g_num) { cout << "caught g exception " << g_num << endl; }
//		cout << "main - finished calling g" << endl;
//	}
//	cout << "main - finished calling f" << endl;
//}