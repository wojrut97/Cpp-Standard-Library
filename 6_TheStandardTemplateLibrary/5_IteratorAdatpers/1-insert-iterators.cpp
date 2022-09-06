#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <list>
#include <iterator>
#include <deque>
#include <algorithm>

using namespace std;

template <typename T>
void print(const T& coll){
    for(auto item : coll){
        cout << item << " ";
    }
    cout << endl;
}

int main(){
    list<int> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    vector<int> coll2;
    // Copy elements by push_back
    copy(coll1.cbegin(), coll1.cend(), back_inserter(coll2));
    print(coll2);

    deque<int> coll3;
    // Copy elements by push_front (reverses the values)
    copy(coll1.cbegin(), coll1.cend(), front_inserter(coll3));
    print(coll3);

    set<int> coll4;
    // Copy elements by push_front (reverses the values)
    copy(coll1.cbegin(), coll1.cend(), inserter(coll4, coll4.begin()));
    print(coll4);

    unordered_set<int> coll5;
    // Copy elements by push_front (reverses the values)
    copy(coll1.cbegin(), coll1.cend(), inserter(coll5, coll5.begin()));
    print(coll5);
}