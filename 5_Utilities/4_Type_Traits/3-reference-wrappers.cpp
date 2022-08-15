#include <iostream>
#include <vector>

using namespace std;

class MyClass{

};

template <typename T>
void foo(T val){
    cout << "foo val: " << val << endl;
}

int main(){
    int x = 5;
    foo(ref(x));        // T becomes int&
    foo(cref(x));       // T becomes const int&

    // vector<MyClass&> vec;       // ERROR
    vector<reference_wrapper<MyClass>> vec;      // OK
}