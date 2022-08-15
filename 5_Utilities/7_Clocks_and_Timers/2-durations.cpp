#include <iostream>
#include <chrono>
#include <ratio>
#include <algorithm>
#include <iomanip>

using namespace std;

template <typename V, typename R>
ostream& operator<<(ostream& os, const chrono::duration<V,R>& d){
    os << "[" << d.count() << " of " << R::num << "/" << R::den << "s]";
    return os;
}

int main(){
    // Example of durations, the second argument is the base given in seconds
    chrono::duration<int>                   twentySeconds(20);
    chrono::duration<double, ratio<60>>     halfAMinute(0.5);
    chrono::duration<long, ratio<1,1000>>   oneMillisecond(1);

    // Better usage:
    chrono::seconds         betterTwentySeconds(20);
    chrono::hours           betterDay(24);
    chrono::milliseconds    betterOneMillisecond(1);

    chrono::seconds         d1(32);
    chrono::milliseconds    d2(10);

    // We can do arithmetic with chrono
    chrono::milliseconds diff = d1 - d2;
    cout << "difference in milliseconds: " << diff << endl;

    cout << "d1 < d2: " << (d1 < d2 ? "true" : "false") << endl;

    chrono::milliseconds ms;                                               // 0 milliseconds
    ms += betterTwentySeconds + betterDay;                                      // 86,400,000 milliseconds
    --ms;                                                                       // 86,399,999 milliseconds
    ms *= 2;                                                                    // 172,839,998 milliseconds
    cout << ms << " ms" << endl;
    cout << chrono::nanoseconds(ms) << " ns" << endl;    // We can convert

    // Casting when there is possibility of losing information:
    // chrono::seconds s1 = halfAMinute;   // ERROR
    chrono::seconds s1 = chrono::duration_cast<chrono::seconds>(halfAMinute);   // OK

    // Splitting
    chrono::hours hh = chrono::duration_cast<chrono::hours>(ms);
    chrono::minutes mm = chrono::duration_cast<chrono::minutes>(ms % chrono::hours(1));
    chrono::seconds ss = chrono::duration_cast<chrono::seconds>(ms % chrono::minutes(1));
    cout << setfill('0') << setw(2) << hh.count() << "::" << setw(2) << mm.count() << "::" << setw(2) << ss.count() << endl;
}