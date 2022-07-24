#include <iostream>

using namespace std;

template <typename T1, typename T2>
auto sum(T1 x, T2 y) -> decltype(x + y){
    return x + y;
}

int main(){
    cout << "sum of 2 and 9000: " << sum(2, 9000) << endl;
}