#include <memory>
#include <iostream>
#include <string>

using namespace std;

class Example{
    public:
        int * ptr;
    
    Example(){
         ptr = new int[10];
    };
    ~Example(){
        delete[] ptr;
    }
    Example(const Example& ex){
        this->ptr = new int[10];
        copy(ex.ptr, ex.ptr + 10, this->ptr); 
    }
    const Example& operator=(const Example& ex){
        if (&ex == this){
            return *this;
        }
        delete[] this->ptr;
        this->ptr = new int[10];
        copy(ex.ptr, ex.ptr + 10, this->ptr);
        return *this;
    }
    Example(Example&& ex){
        this->ptr = ex.ptr;
        delete ex.ptr;
    }
    Example& operator=(Example&& ex){
        if(&ex == this){
            return *this;
        }
        delete[] this->ptr;
        this->ptr = ex.ptr;
        ex.ptr = nullptr;
        return *this;
    }
    
};

class ExampleDeleter{
    public:
        void operator()(Example* ex){
            cout << "Deleting Example object!" << endl;
            delete ex;
        }
};

void foo(){
    // unique_ptr<string> up = new string("Woj");       // It's an ERROR
    unique_ptr<string> up(new string("Woj"));
    (*up)[0] = 'M';
    up->append("tek");
    cout << *up << " is at " << up.get() << endl;

    string* ptr_to_str = up.release();           // Releasing unique pointer

    // We can check if unique pointer points to a resource using bool() operator
    if (up){
        cout << "unique_ptr points to " << *up << endl;
    }

    // If 'up' weren't released by release() method, It would've been released here, at the end of scope
}

void sink(unique_ptr<Example> up){
    return;
}

unique_ptr<Example, ExampleDeleter> source(){
    unique_ptr<Example, ExampleDeleter> up(new Example);
    return up;          // move() isn't required, compiler does the optimization by itself
}

void g(){
    unique_ptr<Example, ExampleDeleter> p;

    for(int i = 0 ; i < 10 ; ++i){
        p = source();                   // no data leaks, old resources released when new ones are being assigned
    }
}   // the last p is being deleted

int main(){
    foo();

    string *hi = new string("hello");
    unique_ptr<string> up1(hi);
    // unique_ptr<string> up2(hi);     // RUNTIME ERROR, up1 and up2 points to the exact same data

    unique_ptr<Example> ex_ptr1(new Example);
    // unique_ptr<Example> ex_ptr2(ex_ptr1);    // ERROR
    unique_ptr<Example> ex_ptr3(move(ex_ptr1));    // Using move semantics is OK

    unique_ptr<Example> another_ex_ptr1(new Example);
    unique_ptr<Example> another_ex_ptr2(new Example);

    another_ex_ptr2 = move(another_ex_ptr1);    // Again it's OK, using move assignment

    sink(move(another_ex_ptr2));                // another_ex_ptr2 looses it's ownership

    cout << "another_ex_ptr1: " << another_ex_ptr1.get() << endl;
    cout << "another_ex_ptr2: " << another_ex_ptr2.get() << endl;

    g();

    // Dealing with arrays

    // unique_ptr<string> up(new string[10]);   // ERROR
    unique_ptr<string[]> up(new string[10]);    // OK

    for (int i = 0; i < 10; i++)
    {
        up[i] = "A";
        up[i].append(to_string(i));
    }

    for (int i = 0; i < 10; i++)
    {
        cout << up[i] << endl;
    }
}