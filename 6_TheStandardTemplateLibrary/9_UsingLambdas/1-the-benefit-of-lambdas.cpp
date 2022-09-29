#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> coll = { 1, 3, 19, 5 ,13, 7, 11, 2, 17};

    int x = 5, y = 12;
    auto pos = find_if(coll.begin(), coll.end(), 
        [=](int i){
            return i > x && i < y;
        }
        );
    cout << "Found: " << *pos << endl;
    
    // The benefits of lambdas:
    // 1. You don't have to scroll up to search for a function
    // 2. Better optimization by the compiler

    // Sorting criterion


}