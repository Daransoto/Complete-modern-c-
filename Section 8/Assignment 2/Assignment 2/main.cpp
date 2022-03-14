#include <string>
#include <iostream>
enum class Case { SENSITIVE, INSENSITIVE };

std::string ToLower(const std::string& str) {
    std::string lower{};
    for (char ch : str)
        lower += tolower(ch);
    return lower;
}

size_t Find(
    const std::string& source,         //Source string to be searched
    const std::string& search_string,  //The string to search for
    Case searchCase = Case::INSENSITIVE,//Choose case sensitive/insensitive search
    size_t offset = 0) {                //Start the search from this offset

    std::string src{ source }, search{ search_string };
    if (searchCase == Case::INSENSITIVE) {
        src = ToLower(source);
        search = ToLower(search);
    }

    return src.find(search, offset);

        /*
        return position of the first character
        of the substring, else std::string::npos
        */
}

int main() {
    std::string src{ "Oh, Hello world" }, se{ "hElLo WoRlD" };
    std::cout << Find(src, se) << std::endl;
}