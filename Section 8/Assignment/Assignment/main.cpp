#include <string>
#include <iostream>

std::string ToUpper(const std::string& str) {
	std::string upper{};
	for (char ch : str)
		upper += toupper(ch);
	return upper;
}
std::string ToLower(const std::string& str) {
	std::string lower{};
	for (char ch : str)
		lower += tolower(ch);
	return lower;
}
int main() {
	std::cout << ToUpper("Hello") << std::endl;
	std::cout << ToLower ("I'M NOT YELLING!!") << std::endl;
}