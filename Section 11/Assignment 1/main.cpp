#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include <string>

/* For this to work in visual studio 2019, you'll need to add _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING to the 
preprocessor directives */

int main() {
	using namespace std::experimental::filesystem;

	const int BUFFER_SIZE = 512;
	
	path source(current_path());
	source /= "main.cpp";
	path dest(current_path());
	dest /= "copy.cpp";

	if (is_regular_file(dest)) {
		int cont{};
		std::cout << "File " << dest << " will be overwritten, do you want to continue?(1: Yes, 2: No): ";
		std::cin >> cont;
		if (cont == 2)
			return 0;
		else if (cont != 1) {
			std::cout << "Answer must be 1 or 2" << std::endl;
			return -1;
		}
	}

	std::ifstream input{ source, std::ios::binary | std::ios::in };
	if (!input) {
		std::cout << "Source file could not be opened" << std::endl;
		return -1;
	}

	std::ofstream output{ dest, std::ios::binary | std::ios::out };
	if (!output) {
		std::cout << "Destination file could not be opened" << std::endl;
		input.close();
		return -1;
	}

	auto size = file_size(source);
	char buffer[BUFFER_SIZE]{};
	int iterations = size / BUFFER_SIZE;
	int remaining = size % BUFFER_SIZE;
	iterations += remaining ? 1 : 0;
	int read_sz = BUFFER_SIZE;

	for (int i = 1; i <= iterations; i++) {
		if (i == iterations && remaining) {
			memset(buffer, '\0', BUFFER_SIZE);
			read_sz = remaining;
		}
			

		if (!input.read(buffer, read_sz)) {
			std::cout << "Could not read from source" << std::endl;
			input.close();
			output.close();
			return -1;
		}

		if (!output.write(buffer, read_sz)) {
			std::cout << "Could not write to destination" << std::endl;
			input.close();
			output.close();
			return -1;
		}
	}

	input.close();
	output.close();

	return 0;
}