#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    auto extremes = minmax({1, 9, 3, 5, 6});
    cout << extremes.first << ", " << extremes.second << endl;
}