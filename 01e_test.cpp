// ручной поиск функций по их искажённым именам с помощью nm lib/miptlib.dll | grep add
#include <iostream>
#include <vector>
#include <dlfcn.h>
#include <unistd.h>

int main() {
    sleep(2);

    void* lib = dlopen("./lib/miptlib.dll", RTLD_LAZY);
    
    auto add = (double(*)(double,double))dlsym(lib, "_ZN7miptlib3addEdd");
    auto power = (double(*)(double,int))dlsym(lib, "_ZN7miptlib5powerEdi");
    auto circle = (double(*)(double))dlsym(lib, "_ZN7miptlib10circleAreaEd");
    auto mean = (double(*)(std::vector<double>))dlsym(lib, "_ZN7miptlib4meanERKSt6vectorIdSaIdEE");

    std::cout << miptlib::add(3, 4) << std::endl;
    std::cout << miptlib::power(2, 5) << std::endl;
    std::cout << miptlib::circleArea(5) << std::endl;

    std::vector<double> data = {1, 2, 3, 4, 5};

    std::cout << miptlib::mean(data) << std::endl;

    dlclose(lib);
}