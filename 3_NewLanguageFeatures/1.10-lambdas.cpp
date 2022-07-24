#include <iostream>
#include <functional>

using namespace std;

// The function that returns lambda
function<int(int, int)> returnLambda(){
    return [] (int x, int y) -> int{
        return x + y;
    };
}


int main(){
    // Calling directly
    [] {
        std::cout << "hello lambda" << endl;
    }();

    // Assigning to a variable
    auto l = [] {
        std::cout << "hello lambda" << endl;
    };

    // Lambda can return a value, specifying return type is not required
    // Lambda can have arguments and specifiers
    auto la = [] (const string& s) -> int {
        cout << s << endl;
        return 1;
    };

    cout << la("my name is lambda") << endl;

    // You can specify a capture to access data of outer scope
    // [=] - outer scope is passed by value
    // [&] - outer scope is passed by reference
    int x = 0, y = 42;
    auto qqq = [x, &y] {
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
        // x++;     // error: increment of read-only variable ‘x’
        y++;
    };
    x = y = 77;
    qqq();
    qqq();
    cout << "at the end, x: " << x << ", y: " << y << endl;


    // You can use mutable to modify data passed by value

    int id = 20;
    auto f = [id] () mutable{
        cout << "id: " << id << endl;
        id++;   // it's OK due to mutable specifier
    };
    f();
    f();
    f();
    cout << "at the end, id: " << id << endl;


    // Lambda returned from the function
    auto sum = returnLambda();
    cout << "1 + 2 = " << sum(1, 2) << endl;

}