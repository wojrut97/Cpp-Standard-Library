#include <iostream>

using namespace std;

constexpr int square(int x){
    return x*x;
}

int main(){
    int main[square(4)];
}