#include <iostream>

int& getRefToMax(int& x, int& y)
{
    if (x > y)
        return x;
    else
        return y;
}

int main()
{
    int a = 10;
    int b = 20;

    getRefToMax(a, b) += 1;

    std::cout << a << " " << b << std::endl;
}