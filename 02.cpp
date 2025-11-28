#include <iostream>
class Cat
{
	int x;
public:
	explicit Cat(int x) : x(x)   {std::cout << "Constructor from int\n";}
	Cat() : x(0)                 {std::cout << "Default Constructor\n";}
	Cat(const Cat& c) : x(c.x)   {std::cout << "Copy Constructor\n";}
	Cat& operator=(const Cat& c) {x = c.x; std::cout << "Assignment\n"; return *this;}
	~Cat()                       {std::cout << "Destructor\n";}
};
// 1
int main()
{
    Cat a;
}
// 2
int main()
{
    Cat a = 10;
}
// 3
int main()
{
    Cat a{10};
}
// 4
int main()
{
    Cat a{};
    Cat b{a};
}
// 5
int main()
{
    Cat a;
    Cat b = a;
}
// 6
int main()
{
    Cat a;
    Cat b;
    b = a;
}
// 7
void func(Cat a) {}
int main()
{
    Cat b;
    func(b);
}
// 8
void func(Cat& a) {}
int main()
{
    Cat b;
    func(b);
}
// 9
void func(Cat a) {}
int main()
{
    func(10);
}
// 10
void func(Cat a) {}
int main()
{
    func(Cat{10});
}
// 11
class Dog
{
    Cat y;
public:
    Dog(const Cat& a) : y(a) {}
};
int main()
{
    Cat a;
    Dog b(a);
}
// 12
class Dog
{
    Cat y;
public:
    Dog(const Cat& a) {y = a;}
};
int main()
{
    Cat a;
    Dog b(a);
}
// 13
int main()
{
    Cat* p = new Cat;
    delete p;
}
// 14
#include <cstdlib>
int main()
{
    Cat* p = (Cat*)std::malloc(3 * sizeof(Cat));
    std::free(p);
}
// 15
int main()
{
    Cat* p = new Cat[3];
    delete[] p;
}
// 16
#include <vector>
int main()
{
    std::vector<Cat> v(3);
}
// 17
struct Dog
{
    static Cat y;
};
Cat Dog::y{};

int main()
{
    Dog a;
    Dog b;
}