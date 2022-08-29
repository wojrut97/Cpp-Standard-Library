#include <chrono>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

string asString(const chrono::system_clock::time_point& tp){
    time_t t = chrono::system_clock::to_time_t(tp);
    string ts = ctime(&t);
    ts.resize(ts.size() - 1);       // -1 removes the trailing new line character
    return ts;
}

int main(){
    // ctime() includes local time conversion, to have UTC instead we should use asctime(gmtime())

    chrono::system_clock::time_point tp;
    cout << "epoch: " << asString(tp) << endl;

    tp = chrono::system_clock::now();
    cout << "now: " << asString(tp) << endl;

    tp = chrono::system_clock::time_point::min();
    cout << "min: " << asString(tp) << endl;

    tp = chrono::system_clock::time_point::max();
    cout << "max: " << asString(tp) << endl;
}