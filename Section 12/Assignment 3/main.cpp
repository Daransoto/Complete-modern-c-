#include <iostream>


template <typename T>
T Add(T x, T y) {
	return x + y;
}

template <typename T, size_t arrSize>
T ArraySum(T (&pArr)[arrSize]) {
	T sum = 0;
	for (int i = 0; i < arrSize; i++)
		sum += pArr[i];
	return sum;
}

template<size_t arrSize> const char * ArraySum(const char*(&pArr)[arrSize]) {
	int sum = 0;
	for (int i = 0; i < arrSize; i++)
		sum += strlen(pArr[i]);
	char* result = (char *) calloc(sum + 1, 1);
	for (int i = 0; i < arrSize; i++)
		strcat_s(result, sum + 1,pArr[i]);
	return result;
}


template<size_t arrSize> std::string ArraySum(std::string (&pArr)[arrSize]) {
	std::string result;
	for (int i = 0; i < arrSize; i++)
		result += pArr[i];
	return result;
}


template <typename T, size_t arrSize>
T Max(T(&pArr)[arrSize]) {
	T max = pArr[0];
	for (int i = 1; i < arrSize; i++)
		if (pArr[i] > max)
			max = pArr[i];
	return max;
}


template<size_t arrSize> const char * Max(const char*(&pArr)[arrSize]) {
	int max = 0;
	for (int i = 1; i < arrSize; i++)
		if (strcmp(pArr[max], pArr[i]) < 0)
			max = i;
	return pArr[max];
}


template<size_t arrSize> std::string Max(std::string (&pArr)[arrSize]) {
	std::string max = pArr[0];
	for (int i = 1; i < arrSize; i++)
		if (pArr[i] > max)
			max = pArr[i];
	return max;
}

template <typename T, size_t arrSize>
std::pair<T, T> MinMax(T(&pArr)[arrSize]) {
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

template<size_t arrSize> std::pair<char*, char*> MinMax(const char*(&pArr)[arrSize]) {
	int maxlen = 0;
	for (int i = 0; i < arrSize; i++)
		if (strlen(pArr[i]) > maxlen)
			maxlen = strlen(pArr[i]);
	char* min = (char*)calloc(maxlen + 1, 1);
	char* max = (char*)calloc(maxlen + 1, 1);
	strcpy_s(min, maxlen + 1, pArr[0]);
	strcpy_s(max, maxlen + 1, pArr[0]);
	for (int i = 1; i < arrSize; i++) {
		if (strcmp(pArr[i], max) > 0)
			strcpy_s(max, maxlen + 1, pArr[i]);
		else if (strcmp(pArr[i], min) < 0)
			strcpy_s(min, maxlen + 1, pArr[i]);
	}
	return std::pair<char*, char*>{min, max};
}


template<size_t arrSize> std::pair<std::string, std::string> MinMax(std::string (&pArr)[arrSize]) {
	std::string min = pArr[0];
	std::string max = pArr[0];
	for (int i = 1; i < arrSize; i++) {
		if (pArr[i] > max)
			max = pArr[i];
		else if (pArr[i] < min)
			min = pArr[i];
	}
	return std::pair<std::string, std::string>{min, max};
}

int main() {
	std::cout << "Int add: " << Add(3, 5) << std::endl;
	std::cout << "Float add: " << Add(3.2, 5.1) << std::endl;

	int ilist[]{ 3, 2, 1, 3, 2 };
	float flist[]{ 3.0f, 2.1f, 1.2f, 3.3f, 2.4f };
	const char* clist[]{ "aaa", "bbb", "ccc" };
	std::string slist[]{ "abc", "def", "ghi"};
	const char* carrsum = ArraySum(clist);
	std::cout << "Int arrsum: " << ArraySum(ilist) << std::endl;
	std::cout << "Float arrsum: " << ArraySum(flist) << std::endl;
	std::cout << "Char* arrsum: " << carrsum << std::endl;
	free((void *) carrsum);
	std::cout << "string arrsum: " << ArraySum(slist) << std::endl;

	std::cout << "Int max: " << Max(ilist) << std::endl;
	std::cout << "Float max: " << Max(flist) << std::endl;
	std::cout << "Char* max: " << Max(clist) << std::endl;
	std::cout << "String max: " << Max(slist) << std::endl;

	auto ipair = MinMax(ilist);
	auto fpair = MinMax(flist);
	auto cpair = MinMax(clist);
	auto spair = MinMax(slist);
	std::cout << "Int minmax: " << ipair.first << "," << ipair.second << std::endl;
	std::cout << "Float minmax: " << fpair.first << "," << fpair.second << std::endl;
	std::cout << "Char* minmax: " << cpair.first << "," << cpair.second << std::endl;
	free((void*)cpair.first);
	free((void*)cpair.second);
	std::cout << "String minmax: " << spair.first << "," << spair.second << std::endl;
}