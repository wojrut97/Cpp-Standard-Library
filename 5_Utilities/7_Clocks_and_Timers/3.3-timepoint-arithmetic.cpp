#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

string asString (const chrono::system_clock::time_point& tp)
{
    time_t t = chrono::system_clock::to_time_t(tp); // convert to system time
    string ts = ctime(&t); // convert to calendar time
    ts.resize(ts.size()-1); // skip trailing newline
    return ts;
}

int main()
{
    // define type for durations that represent day(s):
    typedef chrono::duration<int,ratio<3600*24>> Days;

    // process the epoch of this system clock
    chrono::time_point<chrono::system_clock> tp;
    cout << "epoch: " << asString(tp) << endl;

    // add one day, 23 hours, and 55 minutes
    tp += Days(1) + chrono::hours(23) + chrono::minutes(55);
    cout << "later: " << asString(tp) << endl;

    // process difference from epoch in minutes and days:
    auto diff = tp - chrono::system_clock::time_point();
    cout << "diff: " << chrono::duration_cast<chrono::minutes>(diff).count() << " minute(s)" << endl;

    Days days = chrono::duration_cast<Days>(diff);
    cout << "diff: " << days.count() << " day(s)" << endl;

    // subtract one year (hoping it is valid and not a leap year)
    tp -= chrono::hours(24*365);
    cout << "-1 year: " << asString(tp) << endl;

    // subtract 250 years (hoping it is valid and ignoring leap years)
    tp -= chrono::duration<int,ratio<3600*24*365>>(250);
    cout << "-250 years: " << asString(tp) << endl;

    // subtract 250 years (hoping it is valid and ignoring leap years)
    tp -= chrono::duration<int,ratio<3600*24*365>>(250);
    cout << "-250 years: " << asString(tp) << endl;

    // This demonstrates that chrono is a duration and a timepoint but not a date/time library. 
    // You can compute with durations and timepoints but still have to take epoch, minimum and maximum timepoints,
    // leap years, and leap seconds into account.
}