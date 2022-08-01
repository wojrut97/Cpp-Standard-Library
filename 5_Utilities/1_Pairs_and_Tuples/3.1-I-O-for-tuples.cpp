#include <tuple>
#include <iostream>

using namespace std;

// Helper: print element with index IDX of tuple with MAX elements
template <int IDX, int MAX, typename... Args>
struct PRINT_TUPLE{
    static void print(ostream& stream, const tuple<Args...>& t){
        stream << get<IDX>(t) << (IDX + 1 == MAX ? "" : ", ");
        PRINT_TUPLE<IDX + 1, MAX, Args...>::print(stream, t);
    }
};

// Partial specialization to end the recursion
template <int MAX, typename... Args>
struct PRINT_TUPLE<MAX,MAX,Args...>{
    static void print(ostream& stream, const tuple<Args...>& t){

    }
};

template <typename... Args>
ostream& operator << (ostream& stream, const tuple<Args...>& t){
    stream << "[";
    PRINT_TUPLE<0, sizeof...(Args), Args...>::print(stream, t);
    return stream << "]";
}

int main(){
    tuple <int, float, string> t(77, 1.1, "it's a little bit complicated");
    cout << "tuple: " << t << endl;
}