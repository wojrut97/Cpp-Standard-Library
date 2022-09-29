#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

template <typename collection>
void print(collection col){
    for_each(col.begin(), col.end(), [](int i){ cout << i << ", ";});
    cout << endl;
}

int main()
{
    deque<int> coll = { 1, 2, 3, 5, 7, 11, 13, 17, 19 };
    print(coll);

    // negate all values in coll
    transform (coll.cbegin(), coll.cend(), coll.begin(), negate<int>());
    print(coll);

    // square all values in coll
    transform (coll.cbegin(), coll.cend(), coll.cbegin(), coll.begin(), multiplies<int>());
    print(coll);
}