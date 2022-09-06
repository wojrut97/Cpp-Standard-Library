#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main(){
    vector<int> coll = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Show me some printing to the standard output
    for (int i = coll.size() - 1 ; i >= 0 ; i--){
        cout << coll[i] << " ";
    }

    cout << endl;
    
    // I said printing to the standard output
    for( int item : coll){
        cout << item << " ";
    }

    cout << endl;

    // Perfection
    copy(coll.crbegin(), coll.crend(), 
        ostream_iterator<int>(cout, " "));

    // crbegin and crend return reverse iterator
}