#include <list>
#include <set>
#include <unordered_set>
#include <iostream>

using namespace std;

void asList(){
    list<char> coll; // list container for character elements
    // append elements from ’a’ to ’z’
    for (char c='a'; c<='z'; ++c) {
        coll.push_back(c);
    }
    list<char>::const_iterator pos;
    for (pos = coll.begin(); pos != coll.end(); ++pos) {
        cout << *pos << ' ';
    }
    cout << endl;
}

void asSet(){
    // Doesn't allow duplicates
    set<int> coll;

    // We can simply call:
    coll.insert ( { 99, 98, 97, 66, 11, 99, 98 } );

    // cbegin and cend return constant iterator
    for(auto pos = coll.cbegin() ; pos != coll.cend() ; ++pos){
        cout << *pos << ' ';
    }
    cout << endl;
}

void asMultiset(){
    // Allows duplicates
    multiset<int> coll;
    coll.insert ( { 99, 98, 97, 66, 11, 99, 98 } );

    for(auto pos = coll.cbegin() ; pos != coll.cend() ; ++pos){
        cout << *pos << ' ';
    }
    cout << endl;
}

void asUnorderedMultiset(){
    unordered_multiset<int> coll;
    coll.insert ( { 99, 98, 97, 66, 11, 99, 98 } );
    for (auto elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;

    // insert one more element
    coll.insert(25);

    // print all elements again
    // Note how adding even one element changes the possible output
    // However it's guaranteed that same elements are located next to each other
    for (auto elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    cout << "asList: "; asList();
    cout << "asSet: "; asSet();
    cout << "asMultiset: "; asMultiset();
    cout << "asUnorderedMultiset: "; asUnorderedMultiset();

    // Important note on iterators:
    // To write generic code that is as independent of the container type as possible, you should not
    // use special operations for random-access iterators. For example, the following loop works with any
    // container:
    //   for (auto pos = coll.begin(); pos != coll.end(); ++pos) {
    //      ...
    //   }
    // However, the following does not work with all containers:
    //   for (auto pos = coll.begin(); pos < coll.end(); ++pos) {
    //      ...
    //   }
}