#include <iostream>
#include <vector>

using namespace std;

//alias templates
template <typename T>
using Pair = std::pair<T, T>; 

//variadic templates
template<typename T>
void print(const T& arg){
    cout << arg << endl;
}

template <typename T, typename... Types>
void print(const T& firstArg, const Types&... args){
    cout << firstArg << endl;
    print(args...);
}
//variadic templates

int main(){
    print("This", "is", "just", "a", "test");
    Pair<int> foo = {1, 2};
}