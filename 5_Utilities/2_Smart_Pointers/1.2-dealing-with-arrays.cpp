#include <iostream>
#include <memory>

using namespace std;

int main(){
    // When using new[] operator you have to pass a functor which will call delete[] later 
    shared_ptr<int> p1(new int[10], [](int *p){delete[] p;});

    // Another way
    shared_ptr<int> p2(new int[10], default_delete<int[]>());

    // Unique pointer can own an array
    unique_ptr<int[]> p3(new int[10]);      // OK
    // shared_ptr<int[]> p4(new int[10]);      // ERROR, won't compile

    // When using own delter with unique_ptr you have to pass a second template argument
    unique_ptr<int, void(*)(int*)> p4(new int[10], [](int* p){ delete[] p;});

    //To sum up, unique_ptr and shared_ptr deal with deleters in slightly different way and require special treatment
}