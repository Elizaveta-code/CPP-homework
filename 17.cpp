#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

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

std::vector<std::vector<std::size_t>> calculate_word_lengths(const std::string& filename) {
    std::vector<std::vector<std::size_t>> res;
    std::ifstream file(filename);
    
    for (std::string line; std::getline(file, line); ) {
        std::vector<std::string> words = split(line, ' ');
        if (!words.empty()) {
            std::vector<std::size_t> line_lengths;
            for (const std::string& word : words)
                line_lengths.push_back(word.length());
            res.push_back(std::move(line_lengths));
        }
    }
    return res;
}

void print(const std::vector<std::vector<std::size_t>>& res)
{
    std::cout << "{";
    for (std::size_t i = 0; i < res.size(); ++i) {
        std::cout << "{";
        for (std::size_t j = 0; j < res[i].size(); ++j) {
            std::cout << res[i][j];
            if (j < res[i].size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "}";
        if (i < res.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;
}

int main()
{
    auto res = calculate_word_lengths("test.txt");
    print(res);
}