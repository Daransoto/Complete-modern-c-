#include <iostream>

void Add(int a, int b, int& result) {
	result = a + b;
}
void Factorial(int a, int& result) {
	result = 1;
	for (int i = 1; i <= a; i++) {
		result *= i;
	}
}
void Swap(int& a, int& b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

int main() {
	using namespace std;
	int res = 0, a = 47, b=1337;
	Add(3, 8, res);
	cout << "Adding 3 and 8: " << res << endl;
	Factorial(5, res);
	cout << "Factorial of 5: " << res << endl;
	Swap(a, b);
	cout << "a is now " << a << ", and b is " << b << endl;
}