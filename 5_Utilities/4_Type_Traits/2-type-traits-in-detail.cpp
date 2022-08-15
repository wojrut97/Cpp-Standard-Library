#include <type_traits>
#include <iostream>
#include <string>

using namespace std;

int main(){
    // Type predicates
    cout << "is_const<int>::value = " << is_const<int>::value << endl; // false
    cout << "is_const<const volatile int>::value = " << is_const<const volatile int>::value << endl; // false
    cout << "is_const<int* const>::value = " << is_const<int* const>::value << endl; // true
    cout << "is_const<const int*>::value = " << is_const<const int*>::value << endl; // false

    // Traits for Type Relations
    cout << "is_assignable<int, int>::value = " << is_assignable<int, int>::value << endl; // false
    cout << "is_assignable<int&, int>::value = " << is_assignable<int&, int>::value << endl; // true
    cout << "is_assignable<int&&, int>::value = " << is_assignable<int&&, int>::value << endl; // false
    cout << "is_assignable<string, char*>::value = " << is_assignable<string, char*>::value << endl; // true 
    cout << "is_assignable<char*, string>::value = " << is_assignable<char*, string>::value << endl; // false 

    cout << "is_constructible<int>::value = " << is_constructible<int>::value << endl; // true
    cout << "is_constructible<int, int>::value = " << is_constructible<int, int>::value << endl; // true
    cout << "is_constructible<int, void*>::value = " << is_constructible<int, void*>::value << endl; // false
    cout << "is_constructible<string, const char*, int, int>::value = " << is_constructible<string, const char*, int, int>::value << endl; // true

    // Other type modifiers
    cout << "rank<int>::value = " << rank<int>::value << endl;
    cout << "rank<int[]>::value = " << rank<int[]>::value << endl;
    cout << "rank<int[5][7]>::value = " << rank<int[5][7]>::value << endl;
    cout << "extent<int[5][7]::value = " << extent<int[5][7]>::value << endl;

    remove_all_extents<int[5][6]>::type A;
}