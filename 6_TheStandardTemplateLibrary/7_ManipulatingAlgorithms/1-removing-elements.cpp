#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>

using namespace std;

template <typename T>
void print(T coll){
    for(auto item : coll)
        cout << item << " ";
    cout << endl;
}

int main(){
    list<int> my_name_is_list;
    for (int i = 0; i < 6; i++)
    {
        my_name_is_list.push_back(i);
        my_name_is_list.push_front(i);
    }

    cout << "before remove: " << endl;
    print(my_name_is_list);             // 5 4 3 2 1 0 0 1 2 3 4 5

    remove(my_name_is_list.begin(), my_name_is_list.end(), 3);

    cout << "after remove: " << endl;
    print(my_name_is_list);             // 5 4 2 1 0 0 1 2 4 5 4 5

    // what happend? remove did't update the new end of the container
    // Fix:

    list<int> new_list;
    for (int i = 0; i < 6; i++)
    {
        new_list.push_back(i);
        new_list.push_front(i);
    }

    // We have to "refresh" a new size manually
    auto new_end = remove(new_list.begin(), new_list.end(), 3);
    new_list.erase(new_end, new_list.end());
    
    cout << "after remove on a new list: " << endl;
    print(new_list);
}