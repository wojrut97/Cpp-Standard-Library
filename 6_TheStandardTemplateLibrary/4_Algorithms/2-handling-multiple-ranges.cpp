#include <algorithm>
#include <list>
#include <vector>
using namespace std;

int main()
{
    list<int> coll1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> coll2;

    // Overwrites nonexisting elements in the destination
    // Make sure that second range (container) has at least as many elements as the first one!
    /* copy (coll1.cbegin(), coll1.cend(), coll2.begin()); */    // RUNTIME ERROR

    // Fix:

    coll2.resize(coll1.size());
    copy (coll1.cbegin(), coll1.cend(), coll2.begin());   // OK

}