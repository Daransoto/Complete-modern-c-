#include <iostream>
#include <vector>
#include <typeinfo>


struct {
	template <typename T>
	T operator()(T first, T second) {
		return first > second ? first : second;
	}
} max_struct;

struct
{
	template <typename T>
	bool operator()(T first, T second) {
		return first > second;
	}
} greater_struct;

struct {
	template <typename T>
	bool operator()(T first, T second) {
		return first < second;
	}
} less_struct;

struct {
	template <typename T>
	auto operator()(T ItrBegin, T ItrEnd) {
		auto min = *ItrBegin;
		auto max = *ItrBegin;
		for (T i = ItrBegin; i != ItrEnd; i++) {
			if (*i < min)
				min = *i;
			else if (*i > max)
				max = *i;
		}
		return std::pair<decltype(min), decltype(max)>{min, max};
	}
} minmax_struct;

int main() {
	using namespace std;

	auto max_lambda = [](auto first, auto second) {
		return first > second ? first : second;
	};

	auto greater_lambda = [](auto first, auto second) {
		return first > second;
	};

	auto less_lambda = [](auto first, auto second) {
		return first < second;
	};

	auto minmax_lambda = [](auto ItrBegin, auto ItrEnd) {
		auto min = *ItrBegin;
		auto max = *ItrBegin;

		for (auto i = ItrBegin; i != ItrEnd; i++) {
			if (*i < min)
				min = *i;
			else if (*i > max)
				max = *i;
		}
		return std::pair<decltype(min), decltype(max)>(min, max);
	};

	vector<int> v{ 3,1,5,2,6,8,4,5,9,2 };

	cout << max_lambda(1, 2) << endl;
	cout << max_struct(2, 1) << endl;
	cout << greater_lambda(1, 2) << endl;
	cout << greater_struct(2, 1) << endl;
	cout << less_lambda(1, 2) << endl;
	cout << less_struct(2, 1) << endl;
	cout << minmax_lambda(v.begin(), v.end()).first << ", " << minmax_lambda(v.begin(), v.end()).second << endl;
	cout << minmax_struct(v.begin(), v.end()).first << ", " << minmax_struct(v.begin(), v.end()).second << endl;


	return 0;
}