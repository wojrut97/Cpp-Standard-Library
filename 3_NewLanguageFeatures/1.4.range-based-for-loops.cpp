#include <stdlib.h>
#include <iostream>
#include <vector>

template <typename X>
void printElements2(const X& coll){
    for (auto iter = coll.begin() ; iter != coll.end() ; iter++)
    {
        std::cout << *iter << std::endl;
    }
    
}

template <typename T>
void printElements(const T& coll){
    for (const auto& elem : coll){
        std::cout << elem << std::endl;
    }
}

int main(){
    std::vector<int> vec {1, 2, 3, 4};
    printElements(vec);
    std::cout << "--------" << std::endl;
    printElements2(vec);
}