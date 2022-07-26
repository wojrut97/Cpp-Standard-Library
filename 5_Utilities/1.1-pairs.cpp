#include <iostream>
#include <utility>
#include <tuple>
#include <functional>

using namespace std;

template <typename T1, typename T2>
ostream& operator<< (ostream& stream, const pair<T1, T2>& p){
    return stream << "[" << p.first << ", " << p.second << "]";
}

int main(){
    pair<int, double> p1 = {1, 0.5};
    pair<int, double> p2 = {999, -0.999};

    cout << "p1: " << p1 << ", " << "p2: " << p2 << endl;
    p1.swap(p2);
    cout << "After swap:" << endl;
    cout << "p1: " << p1 << ", " << "p2: " << p2 << endl;

    auto nice_pair = make_pair(42, '@');            // Don't have to specify the type explicitly


    // With references:

    int i = 0;
    auto p = make_pair(ref(i), ref(i));
    ++p.first;
    ++p.second;
    cout << "i: " << i << endl;

    // l-value reference to a tuple with tie
    pair<char, char> chars = {'c', 'x'};
    char c = '!';
    tie(ignore, c) = chars;
    cout << "Now c is: " << c << endl;
}