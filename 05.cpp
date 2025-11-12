#include <iostream>

struct Book
{
    std::string title;
    int pages;
    float price;
};

bool isExpensive(const Book& book)
{
    return book.price > 1000;
}

int main()
{
    Book b = {"Harry Potter", 100, 1200};    
    std::cout << (isExpensive(b) ? "true" : "false") << std::endl;
}