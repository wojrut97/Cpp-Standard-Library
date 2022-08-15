#include <limits>
#include <iostream>
#include <string>

using namespace std;

// Minimum size of built-in types:
// char             1 byte
// short int        2 bytes
// int              2 bytes
// long int         4 bytes
// long long int    8 bytes
// float            4 bytes
// double           8 bytes
// long double      8 bytes

// Class numeric_limits<>
// The specializations are provided for any fundamental type that can represent numeric
// values: bool, char, signed char, unsigned char, char16_t, char32_t, wchar_t, short,
// unsigned short, int, unsigned int, long, unsigned long, long long, unsigned long
// long, float, double, and long double.



int main(){
    // All members of numeric_limits are declared as constexpr, therefore we can use them where compile-time expressions are required:
    static const int ERROR_VALUE = numeric_limits<char>::max();
    float a[numeric_limits<char>::max()];

    cout << boolalpha;

    cout << "max(short): " << numeric_limits<short>::max() << endl;
    cout << "max(int): " << numeric_limits<int>::max() << endl;
    cout << "max(long): " << numeric_limits<long>::max() << endl;
    cout << endl;

    cout << "max(float): " << numeric_limits<float>::max() << endl;
    cout << "max(double): " << numeric_limits<double>::max() << endl;
    cout << "max(long double): " << numeric_limits<long double>::max() << endl;
    cout << endl;

    cout << "is_signed(char): " << numeric_limits<char>::is_signed << endl;
    cout << endl;

    cout << "is_specialized(string): " << numeric_limits<string>::is_specialized << endl;
}