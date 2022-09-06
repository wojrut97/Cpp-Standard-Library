#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
    set<int> coll = {1, 2, 3, 4, 5, 6, 7, 8};

    copy (coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    int num = coll.erase(3);

    cout << "number of erased elements: " << num << endl;

    copy (coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}