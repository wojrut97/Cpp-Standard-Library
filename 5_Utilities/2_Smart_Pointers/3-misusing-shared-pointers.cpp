#include <memory>
#include <vector>
#include <string>

using namespace std;

class PersonError{
    public:
        string name; 
        shared_ptr<PersonError> mother;
        shared_ptr<PersonError> father;
        vector<shared_ptr<PersonError>> kids;
        PersonError(string n) : name(n){};
        ~PersonError(){};
        void setParentsAndTheirKids (shared_ptr<PersonError> m = nullptr,
                                     shared_ptr<PersonError> f = nullptr){
            mother = m;
            father = f;
            if (m != nullptr){
                m->kids.push_back(shared_ptr<PersonError>(this));    // ERROR
            }
            if (f != nullptr){
                f->kids.push_back(shared_ptr<PersonError>(this));    // ERROR
            }
        }
};

class PersonCorrect : public enable_shared_from_this<PersonCorrect> {
    public:
        string name; 
        shared_ptr<PersonCorrect> mother;
        shared_ptr<PersonCorrect> father;
        vector<shared_ptr<PersonCorrect>> kids;
        PersonCorrect(string n) : name(n){};
        ~PersonCorrect(){};
        void setParentsAndTheirKids (shared_ptr<PersonCorrect> m = nullptr,
                                     shared_ptr<PersonCorrect> f = nullptr){
            mother = m;
            father = f;
            if (m != nullptr){
                m->kids.push_back(shared_from_this());    // OK
            }
            if (f != nullptr){
                f->kids.push_back(shared_from_this());    // OK
            }
        }
        // Using shared_from_this() inside constructor is error as well 
};

int main(){
    int *p = new int;
    shared_ptr<int> sp1(p);
    // shared_ptr<int> sp2(p);      // ERROR: Two shared pointers cannot manage one resource
    // In that case deleter would be called twice for the same resource

    // The following is OK, we are creating a new pointer out of an existing one:
    shared_ptr<int> sp3(new int);
    shared_ptr<int> sp4(sp3);

    // More real-life example with this issue

    shared_ptr<PersonError> mom(new PersonError("Adam's mom"));
    shared_ptr<PersonError> dad(new PersonError("Adam's dad"));
    shared_ptr<PersonError> kid(new PersonError("Adam"));
    kid->setParentsAndTheirKids(mom, dad);      // Here comes the error

    shared_ptr<PersonCorrect> mom2(new PersonCorrect("Eve's mom"));
    shared_ptr<PersonCorrect> dad2(new PersonCorrect("Eve's dad"));
    shared_ptr<PersonCorrect> kid2(new PersonCorrect("Eve"));
    kid2->setParentsAndTheirKids(mom2, dad2);      // Here's ok
}