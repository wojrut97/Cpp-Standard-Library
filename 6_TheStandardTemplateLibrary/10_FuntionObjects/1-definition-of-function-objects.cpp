#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename collection>
void print(collection col){
    for_each(col.begin(), col.end(), [](int i){ cout << i << ", ";});
    cout << endl;
}

class AddValue{
    private:
        int theValue;
    public:
        AddValue(int v) : theValue(v) {}
        void operator()(int& elem) const {
            elem += theValue;
        }
};

int main(){
    list<int> coll = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    print(coll);

    for_each(coll.begin(), coll.end(), AddValue(10));

    print(coll);

}