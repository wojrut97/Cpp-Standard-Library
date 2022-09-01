#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> coll = {2, 5, 6, 4, 3, 2, 1};
    auto minpos = min_element(coll.cbegin(), coll.cend());
    cout << "min: " << *minpos << endl;
    auto maxpos = max_element(coll.cbegin(), coll.cend());
    cout << "min: " << *maxpos << endl;

    sort(coll.begin(), coll.end());

    auto pos3 = find(coll.begin(), coll.end(), 3);

    // Reverse vector only from position of 3 till the end
    reverse(pos3, coll.end());

    for(auto elem : coll){
        cout << elem << ' ';
    }
    cout << endl;

}