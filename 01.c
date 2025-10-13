//a
#include <stdio.h>
#include <stdlib.h>
int main(){
    size_t* p = (size_t*)malloc(sizeof(size_t));
    *p = 123;
    printf("%i/n", *p);
    free(p);
}
//b
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char* p = (char*)malloc(sizeof(char)*9);
    strcpy(p, "Elephant");
    printf("%s\n", *p);
    free(p);
}
//c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char **p = (char**)malloc(sizeof(char*));
    *p = (char*)malloc(14 * sizeof(char));
    strcpy(*p, "Cats and Dogs");
    printf("%s\n", *p);
    free(*p);
    free(p);
}
//d
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct book
{
    char title[50];
    int pages;
    float price;
}
typedef struct book Book;
int main(){
    Book* p = (Book*)malloc(sizeof(Book));
    strcpy(p->title, "Don Quixote");
    p->pages = 1000;
    p->price = 750.0;
    printf("Book: %s, Pages: %i, Price: %g", p->title, p->pages, p->price);
    free(p);
}
//e
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct book
{
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;
int main(){
    Book book_struct;
    Book** p = (Book**)malloc(sizeof(Book*));
    *p = &book_struct;
    strcpy((*p)->title, "Don Quixote");
    (*p)->pages = 1000;
    (*p)->price = 750.0;
    printf("Book: %s, Pages: %i, Price: %g\n", 
           book_struct.title, book_struct.pages, book_struct.price);
    free(p);
}
//f
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct book
{
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;
int main(){
    Book** p = (Book**)malloc(sizeof(Book*)); 
    *p = (Book*)malloc(sizeof(Book));
    strcpy((**p)->title, "Don Quixote");
    (**p)->pages = 1000;
    (**p)->price = 750.0;
    printf("Book: %s, Pages: %i, Price: %g\n", 
           (**p).title, (**p).pages, (**p).price);
    free(*p);
    free(p);
}
//g
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct book
{
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;
int main(){
    Book* p = (Book*)malloc(sizeof(Book)*3);
    strcpy(p[0]->title, "Don Quixote");
    p[0]->pages = 1000;
    p[0]->price = 750.0;

    strcpy(p[1]->title, "Oblomov");
    p[1]->pages = 400;
    p[1]->price = 250.0;

    strcpy(p[2]->title, "The Odyssey");
    p[2]->pages = 500;
    p[2]->price = 500.0;
    printf("Book: %s, Pages: %i, Price: %g\n", p[0].title, p[0].pages, p[0].price);
    printf("Book: %s, Pages: %i, Price: %g\n", p[1].title, p[1].pages, p[1].price);
    printf("Book: %s, Pages: %i, Price: %g\n", p[2].title, p[2].pages, p[2].price);
    free(p);
}
//h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct book
{
    char* title;
    int pages;
    float price;
};
typedef struct book Book;
int main(){
    Book* p = (Book*)malloc(sizeof(Book));
    p->title = (char*)malloc(sizeof(char)*12);
    strcpy(p->title, "Don Quixote");
    p->pages = 1000;
    p->price = 750.0;
    printf("Book: %s, Pages: %i, Price: %g", p->title, p->pages, p->price);
    free(p->title);
    free(p);
}
//i
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book
{
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;

struct library
{
    Book* books;
    int number_of_books;
};
typedef struct library Library;

void library_create(Library* lib, int num_books) {
    lib->books = (Book*)malloc(sizeof(Book) * num_books);
    lib->number_of_books = num_books;
}

void library_set(Library lib, int index, const char* title, int pages, float price) {
    strcpy(lib.books[index].title, title);
    lib.books[index].pages = pages;
    lib.books[index].price = price;
}

Book* library_get(Library lib, int index) {
    return &lib.books[index];
}

void print_book(Book* book) {
    printf("Book: %s, Pages: %d, Price: %g\n", book->title, book->pages, book->price);
}

void library_print(Library lib) {
    for (int i = 0; i < lib.number_of_books; i++) {
        print_book(&lib.books[i]);
    }
}

void library_destroy(Library* lib) {
    free(lib->books);
    lib->books = NULL;
    lib->number_of_books = 0;
}

int main(){    
    Library a;
    library_create(&a, 3);
    library_set(a, 0, "Don Quixote", 1000, 750.0);
    library_set(a, 1, "Oblomov", 400, 250.0);
    library_set(a, 2, "The Odyssey", 500, 500.0);
    library_print(a);
    print_book(library_get(a, 1));
    library_destroy(&a);
}
