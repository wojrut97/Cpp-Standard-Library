#include <list>
#include <algorithm>

using namespace std;

// You should always prefer a member function over an algorithm if good performance is the goal!
 
int main()
{
    list<int> coll;
    // insert elements from 6 to 1 and 1 to 6
    for(int i=1; i<=6; ++i) {
        coll.push_front(i);
        coll.push_back(i);
    }
    
    // remove all elements with value 3 (poor performance)
    coll.erase( remove(coll.begin(), coll.end(), 3), coll.end() );

    // remove all elements with value 4 (good performance)
    coll.remove(4);
}