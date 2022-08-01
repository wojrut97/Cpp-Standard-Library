#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

// shared_ptrs are provided to automatically release resources associated with objects no longer needed

int main(){
    // Let's declare our own deleter
    auto deleter = [](string* p){
        cout << "delete " << *p << ", which is at " << p << endl;
        };
    // shared_ptr<string> pNico = make_shared<string>("nico", [](string* p){ cout << "delete " << *p << ", which is at " << p << endl;});
    // shared_ptr<string> pJutta = make_shared<string>("jutta", [](string* p){ cout << "delete " << *p << ", which is at " << p << endl;});
    shared_ptr<string> pNico(new string("nico"), deleter);
    shared_ptr<string> pJutta(new string("jutta"), deleter);

    (*pNico)[0] = 'N';
    pJutta->replace(0, 1, "J");

    // Vector usually creates its own copy of the elements passed
    vector<shared_ptr<string>> whoMadeCoffee;
    whoMadeCoffee.push_back(pJutta);    
    whoMadeCoffee.push_back(pJutta);      
    whoMadeCoffee.push_back(pNico);    
    whoMadeCoffee.push_back(pJutta);    
    whoMadeCoffee.push_back(pNico);

    for (auto ptr : whoMadeCoffee){
        cout << *ptr << "  ";
    }
    cout << endl;

    *pNico = "Nicolai";

    for (auto ptr : whoMadeCoffee){
        cout << *ptr << "  ";
    }
    cout << endl;

    // So here we should have the following use count:
    // pNico: 3 (1 original + 2 vector's)
    // pJutta: 4 (1 original + 3 vector's)
    cout << "pNico.use_count: " << pNico.use_count() << endl;
    cout << "pJutta.use_count: " << pJutta.use_count() << endl;
}