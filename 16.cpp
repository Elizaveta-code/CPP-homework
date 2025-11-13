#include <iostream>
#include <string>
#include <vector>

void print(const std::vector<std::string>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

std::vector<std::string> split(const std::string& str, char delimiter)
{
    std::vector<std::string> res;
    std::size_t s = 0;
    std::size_t e = str.find(delimiter);
    
    while (e != std::string::npos) {
        res.push_back(str.substr(s, e - s));
        s = e + 1;
        e = str.find(delimiter, s);
    }
    res.push_back(str.substr(s));
    return res;
}

int main()
{
    std::string data = "apple,banana,cherry,durian";
    char delimiter = ',';
    std::vector<std::string> parts = split(data, delimiter);
    for (std::size_t i = 0; i < parts.size(); ++i)
        std::cout << parts.at(i) << std::endl;
}