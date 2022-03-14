#include <string>
#include <iostream>
#include <vector>
enum class Case { SENSITIVE, INSENSITIVE };

std::string ToLower(const std::string& str) {
    std::string lower{};
    for (char ch : str)
        lower += tolower(ch);
    return lower;
}

std::vector<int>
FindAll(
    const std::string& target,              //Target string to be searched
    const std::string& search_string,       //The string to search for
    Case searchCase = Case::INSENSITIVE,    //Choose case sensitive/insensitive search
    size_t offset = 0) {                    //Start the search from this offset
    std::string src{ target }, search{ search_string };
    int found{};
    std::vector<int> result{};
    if (searchCase == Case::INSENSITIVE) {
        src = ToLower(target);
        search = ToLower(search);
    }
    while ((found = src.find(search, offset)) != -1) {
        result.push_back(found);
        offset = found + 1;
    }
    return result;

       /*
       Return indices of found strings,
       else an empty vector
       */
}

int main() {
    std::string src{ "Oh, Hello world, I know programmers always start with hello world, but I just wanted to say hello world!" }, se{ "hElLo WoRlD" };
    for (int elem: FindAll(src, se))
        std::cout << elem << std::endl;
}