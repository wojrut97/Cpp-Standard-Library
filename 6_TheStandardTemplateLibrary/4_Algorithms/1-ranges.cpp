#include <algorithm>
#include <list>
#include <iostream>

using namespace std;

int main(){
    list<int> coll;

    // insert elements from 20 to 40
    for (int i=20; i<=40; ++i) {
        coll.push_back(i);
    }
    
    // Find position of element with value 3
    // - there is none, so pos3 gets coll.end()
    auto pos3 = find (coll.begin(), coll.end(), // range
    3); // value

    // Reverse the order of elements between found element and the end
    // - because pos3 is coll.end() it reverses an empty range
    reverse (pos3, coll.end());

    // Find positions of values 25 and 35
    auto pos25 = find (coll.begin(), coll.end(), 25);
    auto pos35 = find (coll.begin(), coll.end(), 35);

    // Print the maximum of the corresponding range
    // - note: including pos25 but excluding pos35
    cout << "max: " << *max_element (pos25, pos35) << endl;

    // process the elements including the last position
    cout << "max: " << *max_element (pos25, ++pos35) << endl;


    // ----- Searching with find_if -----
    coll.clear();
    for (int i=40; i>=20; --i) {
        coll.push_back(i);
    }

    auto pos = find_if(coll.begin(), coll.end(),
                    [] (int i) {
                        return i== 25 || i == 35;
                    });
    if (pos == coll.end()){
        return 1;
    }
    else if (*pos == 25){
        cout << "25 comes first" << endl;
        pos25 = pos;
        pos35 = find(++pos, coll.end(), 35);
    }
    else {
        cout << "35 comes first" << endl;
        pos35 = pos;
        pos25 = find(++pos, coll.end(), 25);
    }
    cout << "pos25: " << *pos25 << endl;
    cout << "pos35: " << *pos35 << endl;
}