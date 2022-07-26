#include <exception>
#include <system_error>
#include <future>
#include <iostream>

using namespace std;

template <typename T>
void processCodeException(const T& e){
    auto c = e.code();
    cerr << "- category:    " << c.category().name() << endl;
    cerr << "- value:    " << c.value() << endl;
    cerr << "- msg:    " << c.message() << endl;
    cerr << "- def category:    " << c.default_error_condition().category().name() << endl;
}


void processException(){
    try {
        throw out_of_range("out_of_range (somewhere, somehow)");
    }
    catch(const ios_base::failure& e){
        cerr << "I/O EXCEPTION: " << e.what() << endl;
        processCodeException(e);
    }
    catch(const system_error& e){
        cerr << "SYSTEM EXCEPTION: " << e.what() << endl;
        processCodeException(e);
    }
    catch(const future_error& e){
        cerr << "FUTURE EXCEPTION: " << e.what() << endl;
        processCodeException(e);
    }
    // catch(const bad_alloc& e){
    //     cerr << "BAD ALLOC EXCEPTION: " << e.what() << endl;
    //     processCodeException(e);
    // }
    // catch(const exception& e){
    //     cerr << "EXCEPTION: " << e.what() << endl;
    //     processCodeException(e);
    // }
    catch(...){
        cerr << "EXCEPTION (unknown)" << endl;
    }
}

int main(){
    processException();
}