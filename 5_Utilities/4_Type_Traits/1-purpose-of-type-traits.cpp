#include <type_traits>
#include <iostream>

using namespace std;

// Example based on is_pointer<>:
template <typename T>
void foo(const T& val){
    if (is_pointer<T>::value){
        cout << "foo called for a pointer" << endl;
    }
    else{
        cout << "foo caled for a value" << endl;
    }
}

template <typename T>
void foo2(const T& val){
    // cout << is_pointer<T>::value ? *val : val << endl;      // This won't work, because the code will be generated with an error
}

template <typename T>
void foo_impl(const T& val, true_type){
    cout << "Called better_foo for a pointer " << *val << endl;
}

template <typename T>
void foo_impl(const T& val, false_type){
    cout << "Called better_foo for a value " << val << endl;
}

template <typename T>
void better_foo(const T& val){
    foo_impl<T>(val, is_pointer<T>());
}

int main(){
    int *p = new int;
    *p = 5;
    foo(p);
    better_foo(p);
}