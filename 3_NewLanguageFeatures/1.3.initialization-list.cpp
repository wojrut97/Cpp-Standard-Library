#include <stdlib.h>
#include <iostream>

int I;
int J{};
int *P;
int *Q{};

int main(){
    int i;
    int j{};
    int *p;
    int *q{};
    std::cout << "i: " << i << std::endl;
    std::cout << "j: " << j << std::endl;
    std::cout << "p: " << p << std::endl;
    std::cout << "q: " << q << std::endl;
    std::cout << "I: " << I << std::endl;
    std::cout << "J: " << J << std::endl;
    std::cout << "P: " << P << std::endl;
    std::cout << "Q: " << Q << std::endl;
}