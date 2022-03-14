#include <iostream>

int Add(int* a, int* b) {
	return *a + *b;
}

void AddVal(int* a, int* b, int* result) {
	*result = *a + *b;
}

void Swap(int* a, int* b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void Factorial(int* a, int* result) {
	*result = 1;
	for (int i = 1; i <= *a; i++) {
		*result *= i;
	}
}

int main() {
	using namespace std;
	int x = 2;
	int y = 3;
	int res = 0;
	cout << "x + y is " << Add(&x, &y) << endl;
	AddVal(&x, &y, &res);
	cout << "result is " << res << endl;
	Swap(&x, &y);
	cout << "Now x is " << x << ", and y is " << y << endl;
	Factorial(&x, &res);
	cout << "Factorial of " << x << " is " << res << endl;
}