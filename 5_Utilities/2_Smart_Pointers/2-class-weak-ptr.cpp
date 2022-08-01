#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Person{
    public:
    string name;
    shared_ptr<Person> mother;
    shared_ptr<Person> father;
    vector<shared_ptr<Person>> kids;
    Person(const string& n, shared_ptr<Person> m = nullptr, shared_ptr<Person> f = nullptr)
    : name(n), mother(m), father(f) {

    }
    ~Person(){
        cout << "delete " << name << endl;
    }
};

shared_ptr<Person> initFamily(const string& name){
    shared_ptr<Person> mom(new Person(name + "'s mom"));
    shared_ptr<Person> dad(new Person(name + "'s dad"));
    shared_ptr<Person> kid(new Person(name, mom, dad));
    mom->kids.push_back(kid);
    dad->kids.push_back(kid);
    return kid;
}


class BetterPerson{
    public:
    string name;
    shared_ptr<BetterPerson> mother;
    shared_ptr<BetterPerson> father;
    vector<weak_ptr<BetterPerson>> kids;
    BetterPerson(const string& n, shared_ptr<BetterPerson> m = nullptr, shared_ptr<BetterPerson> f = nullptr)
    : name(n), mother(m), father(f) {

    }
    ~BetterPerson(){
        cout << "delete " << name << endl;
    }
};

shared_ptr<BetterPerson> initBetterFamily(const string& name){
    shared_ptr<BetterPerson> mom(new BetterPerson(name + "'s mom"));
    shared_ptr<BetterPerson> dad(new BetterPerson(name + "'s dad"));
    shared_ptr<BetterPerson> kid(new BetterPerson(name, mom, dad));
    mom->kids.push_back(kid);
    dad->kids.push_back(kid);
    return kid;
}

int main(){
    shared_ptr<Person> nico = initFamily("nico");
    cout << "nico.use_count: " << nico.use_count() << endl;
    cout << "mother's son: " << nico->mother->kids[0]->name << endl;

    // destructor of Person will never be called, because we have a cyclic reference

    shared_ptr<BetterPerson> marco = initBetterFamily("marco");
    cout << "marco.use_count: " << marco.use_count() << endl;
    if (marco->mother->kids[0].expired() == false){
        cout << "mother's son: " << marco->mother->kids[0].lock()->name << endl;
    }

    // destructor of BetterPerson will be called, because we used weak_ptr in kids reference

    // Be aware of checking weak pointer before use, here's how to do this
    try{
        cout << endl << " --- weak pointer safety --- " << endl << endl; 
        shared_ptr<string> sp(new string("I'm a funny string"));
        weak_ptr<string> wp(sp);
        sp.reset();
        cout << "use_count(): " << wp.use_count() << endl;
        cout << "expired(): " << wp.expired() << endl;
        shared_ptr<string> p(wp);           // will throw std::bad_weak_ptr
    }
    catch(const exception& e){
        cerr << "exception: " << e.what() << endl;
    }
}