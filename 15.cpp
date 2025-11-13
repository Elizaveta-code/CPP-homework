#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

void print(const std::vector<int>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

void print(const int* a, std::size_t n)
{
    for (std::size_t i = 0; i < n; ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

// 1. Перегрузка для std::string
char& get(std::string& str, std::size_t index)
{
    if (index >= str.size()) {
        std::cout << "Error" << std::endl;
        std::exit(1);
    }
    return str[index];
}

// 2. Перегрузка для std::vector<int>
int& get(std::vector<int>& vec, std::size_t index)
{
    if (index >= vec.size()) {
        std::cout << "Error" << std::endl;
        std::exit(1);
    }
    return vec[index];
}

// 3. Перегрузка для обычного массива int
int& get(int* arr, std::size_t size, std::size_t index)
{
    if (index >= size) {
        std::cout << "Error" << std::endl;
        std::exit(1);
    }
    return arr[index];
}

int main()
{
    std::vector<int> v {10, 20, 30, 40, 50};
    get(v, 2) += 1;
    print(v);

    std::string s = "Cat";
    get(s, 0) = 'B';
    std::cout << s << std::endl;

    int a[5] = {10, 20, 30, 40, 50};
    get(a, 5, 2) += 1;
    print(a, 5);
    get(v, 10) = 0;
}