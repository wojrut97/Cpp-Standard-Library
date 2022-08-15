#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void foo(int a, int b){
    cout << "foo: " <<  a << ", " << b << endl;  
}

void bar(int a, int b){
    cout << "bar: " <<  a << ", " << b << endl;  
}

int main(){
    vector<function<void(int, int)>> tasks;
    tasks.push_back(foo);
    tasks.push_back(bar);

    for(auto task : tasks){
        task(10, 20);
    }

    function<void(int, int)> f;
    // f(33, 66);          // throws bad_function_call
}