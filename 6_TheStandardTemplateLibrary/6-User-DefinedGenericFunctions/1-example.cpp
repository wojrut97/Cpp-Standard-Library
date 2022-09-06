#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

// This example defines a generic function that prints an optional string followed by all elements of the
// passed container.

template <typename T>
void print(T collection, const string& optional_string = ""){
    cout << optional_string;
    for(auto item : collection){
        cout << item << " ";
    }
    cout << endl;
}

int main(){
    vector<double> doubles = {1.1, 2.2, 3.3, 4.4};
    print(doubles, "all the elements: ");
}