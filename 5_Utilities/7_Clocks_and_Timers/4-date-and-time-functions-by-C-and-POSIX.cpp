#include <ctime>
#include <iostream>
#include <string>
#include <chrono>

using namespace std;

string asString (const chrono::system_clock::time_point& tp){
    // convert to system time:
    time_t t = chrono::system_clock::to_time_t(tp);
    string ts = ctime(&t); // convert to calendar time
    ts.resize(ts.size()-1); // skip trailing newline
    return ts;
}

chrono::system_clock::time_point makeTimePoint (int year, int mon, int day, int hour, int min, int sec=0){
struct tm t;
t.tm_sec = sec; // second of minute (0 .. 59 and 60 for leap seconds)
t.tm_min = min; // minute of hour (0 .. 59)
t.tm_hour = hour; // hour of day (0 .. 23)
t.tm_mday = day; // day of month (0 .. 31)
t.tm_mon = mon-1; // month of year (0 .. 11)
t.tm_year = year-1900; // year since 1900
t.tm_isdst = -1; // determine whether daylight saving time
time_t tt = mktime(&t);
if (tt == -1) {
    throw "no valid system time";
}
return chrono::system_clock::from_time_t(tt);
}

int main(){
    auto tp1 = makeTimePoint(2010,01,01,00,00);
    cout << asString(tp1) << endl;

    auto tp2 = makeTimePoint(2011,05,23,13,44);
    cout << asString(tp2) << endl;
}