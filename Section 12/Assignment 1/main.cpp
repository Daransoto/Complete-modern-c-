#include <iostream>

template <typename T>
T Add(T x, T y) {
	return x + y;
}

template <typename T>
T ArraySum(T* pArr, int arrSize) {
	T sum = 0;
	for (int i = 0; i < arrSize; i++)
		sum += pArr[i];
	return sum;
}

template <typename T>
T Max(T* pArr, int arrSize) {
	T max = pArr[0];
	for (int i = 1; i < arrSize; i++)
		if (pArr[i] > max)
			max = pArr[i];
	return max;
}

template <typename T>
std::pair<T, T> MinMax(T* pArr, int arrSize) {
	T max = pArr[0];
	T min = max;
	for (int i = 1; i < arrSize; i++) {
		if (pArr[i] > max)
			max = pArr[i];
		else if (pArr[i] < min)
			min = pArr[i];
	}
	return std::pair<T, T>{min, max};
}

int main() {
	std::cout << "Int add: " << Add(3, 5) << std::endl;
	std::cout << "Float add: " << Add(3.2, 5.1) << std::endl;

	int ilist[]{ 3, 2, 1, 3, 2 };
	float flist[]{ 3.0f, 2.1f, 1.2f, 3.3f, 2.4f };
	std::cout << "Int arrsum: " << ArraySum(ilist, 5) << std::endl;
	std::cout << "Float arrsum: " << ArraySum(flist, 5) << std::endl;

	std::cout << "Int max: " << Max(ilist, 5) << std::endl;
	std::cout << "Float max: " << Max(flist, 5) << std::endl;

	auto ipair = MinMax(ilist, 5);
	auto fpair = MinMax(flist, 5);
	std::cout << "Int minmax: " << ipair.first << "," << ipair.second << std::endl;
	std::cout << "Float minmax: " << fpair.first << "," << fpair.second << std::endl;
}