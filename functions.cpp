#include <iostream>
#include <functional>
using namespace std;

 typedef int (*UF) (int, double);
using UF1 = int(*) (int, double);
using UF2 = function<int(int, double)>;

//void main() {
//	int k = 4;
//	int& r = k;
//	
//}