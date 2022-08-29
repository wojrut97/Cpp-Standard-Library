#include <iostream>
#include <ratio>

using namespace std;

template<typename T>
void print(T frac){
    cout << frac.num << "/" << frac.den << endl;
}

int main(){
    ratio<5,3> five_thirds;
    print(five_thirds);

    ratio<25,15> also_five_thirds;
    print(also_five_thirds);

    ratio<42,42> one;
    print(one);

    ratio<0> zero;
    print(zero);

    ratio<7,-3> neg;
    print(neg);

    cout << "five_thirds == also_five_thirds: " << (ratio_equal<decltype(five_thirds), decltype(also_five_thirds)>::value ? "true" : "false") << endl;
}