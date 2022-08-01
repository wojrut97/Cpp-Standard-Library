#include <tuple>
#include <iostream>

using namespace std;

template<typename TupleType, size_t... I>
void print(const TupleType& _tup, index_sequence<I...>){
    (..., (cout << (I == 0 ? "" : ", ") << get<I>(_tup)));
}

template<typename... TupleType>
ostream& operator << (ostream& stream, tuple<TupleType...>& _tup){
    stream << "[";
    print(_tup, make_index_sequence<sizeof...(TupleType)>());
    return stream << "]";
}

int main(){
    tuple <int, float, string> t(77, 1.1, "it's a little bit complicated");
    cout << "tuple: " << t << endl;
}