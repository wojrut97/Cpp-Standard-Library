#include <iostream>
#include <tuple>
#include <complex>
#include <string>

using namespace std;

template <typename... Args>
void tuple_lover(const tuple<Args...> t){
    return;
}

int main(){
    tuple<string, int, int, complex<double>> t;
    tuple<int, float, string> t1(41, 6.3, "nico");

    cout << get<0>(t1) << " ";
    cout << get<1>(t1) << " ";
    cout << get<2>(t1) << " " << endl;

    // Passing an index at runtime is not possible!
    // for (int i = 0 ; i < 3 ; i++){
    //     cout << get<i>(t1) << " " << endl;
    // }

    auto t2 = make_tuple(41, 44, "nico");

    get<1>(t1) = get<1>(t2);

    cout << endl;
    cout << "t1: " << endl;
    cout << "type: " << typeid(get<0>(t1)).name() << ", value: " << get<0>(t1) << endl;
    cout << "type: " << typeid(get<1>(t1)).name() << ", value: " << get<1>(t1) << endl;
    cout << "type: " << typeid(get<2>(t1)).name() << ", value: " << get<2>(t1) << endl;

    cout << endl;
    cout << "t2: " << endl;
    cout << "type: " << typeid(get<0>(t2)).name() << ", value: " << get<0>(t2) << endl;
    cout << "type: " << typeid(get<1>(t2)).name() << ", value: " << get<1>(t2) << endl;
    cout << "type: " << typeid(get<2>(t2)).name() << ", value: " << get<2>(t2) << endl;
    cout << endl;

    if (t1 == t2){
        cout << "The tuples are equal" << endl;
    }
    else{
        cout << "The tuples are not equal" << endl;
    }
    cout << endl;
    // The use of tie() creates a tuple of references

    tuple<int, float, string> foo(70, 3.14, "tuples, huh?");
    int i;
    float f;
    string s;

    tie(i, f, s) = foo;

    cout << "i = " << i << ", f = " << f << ", s = \"" << s << "\"" << endl;
    cout << endl;

    // The use of ignore() allows ignoring tuple elements while parsing with tie()

    get<0>(foo) = 400;
    get<2>(foo) = "it's nice";

    tie(i, ignore, s) = foo;

    cout << "i = " << i << ", f = " << f << ", s = \"" << s << "\"" << endl;

    // Tuples and Initializer Lists
    // You can’t use the assignment syntax to initialize a tuple because that is considered to be an implicit conversion
    
    tuple_lover(make_tuple(42));    // This is OK, cause we convert explicitly
    // tuple_lover(42);    // That's an ERROR

}