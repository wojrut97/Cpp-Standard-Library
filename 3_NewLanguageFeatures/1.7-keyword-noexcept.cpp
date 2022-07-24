#include <iostream>
#include <vector>

using namespace std;


int foo() noexcept{
    return 65;
};

// The first noexcept is a specifier (when true it means the function won't throw an exception)
// The second noexcept is an operator that evalutaes if the function won't throw an exception
// So in this dummy example, swap won't be throwing exceptions when x.swap won't be throwing exceptions
template<typename T>
void swap (T& x, T& y) noexcept(noexcept(x.swap(y))){
    x.swap(y);
}

int main(){
    vector<int> first = {1, 2, 3};
    vector<int> second = {99, 98, 97};
    swap(first, second);
    cout << "first: " << first[0] << ", " << first[1] << ", " << first[2] << endl; 
    cout << "second: " << second[0] << ", " << second[1] << ", " << second[2] << endl; 
}