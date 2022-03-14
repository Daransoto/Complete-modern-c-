#include<iostream>

template <typename T, typename...Params>
T CreateObject(Params...args) {
	return T(args...);
}

int main() {
	auto i = CreateObject<int>(5);
	auto s = CreateObject<std::string>();
	auto p = CreateObject<std::pair<int, int>>(2, 3);

	std::cout << "i: " << i << std::endl << "s: " << s << std::endl << "p: " << p.first << ", " << p.second << std::endl;
}