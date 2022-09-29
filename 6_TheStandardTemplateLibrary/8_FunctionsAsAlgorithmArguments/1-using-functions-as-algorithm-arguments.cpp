#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

template <typename T>
void print(T coll){
    for(auto item : coll){
        cout << item << " ";
    }
}

template <typename T>
void print_elem(T elem){
    cout << elem << " ";
}

int square(int val){
    return val*val;
}

int main(){
    vector<int> coll1 = {1, 2, 3, 4, 5};
    multiset<int> coll2 = {9, 9, 9, 9, 6, 6, 6, 6};

    // Simplest example for_each function
    cout << "coll1 before: " << endl;
    for_each( coll1.begin(), coll1.end(), print_elem<int>);
    cout << endl;

    cout << "coll2: " << endl;
    print(coll2);
    cout << endl;

    transform(coll2.cbegin(), coll2.cend(), back_inserter(coll1), square);

    cout << "coll1 after: " << endl;
    print(coll1);
    cout << endl;
}