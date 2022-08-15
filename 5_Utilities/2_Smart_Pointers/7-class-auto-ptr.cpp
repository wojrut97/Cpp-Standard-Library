#include <memory>
#include <iostream>

using namespace std;

template <typename T>
void badPrint(auto_ptr<T> p){
    if (p.get() != NULL){
        cout << *p << endl;
    }
}

int main(){
    auto_ptr<int> p(new int);
    *p = 100;
    badPrint(p);
    *p = 10;        // RUNTIME ERROR!
    // With unique_ptr  such a mistake is no longer possible, because we would have to use move() explicily
}
