#include "complex.h"

int main(){

    vv::ComplexNumber c(1, 9);
    vv::ComplexNumber c1 = c;
    vv::ComplexNumber c2;

    std::cout << c << std::endl; 
    std::cout << c1 << ", " << c2 << std::endl;

    return 0;
}