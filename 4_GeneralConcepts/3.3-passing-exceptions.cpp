#include <exception>

std::exception_ptr eptr;

using namespace std;

void foo(){
    try{
        throw;
    }
    catch(...){
        eptr = std::current_exception();
    }
}

void bar(){
    if (eptr != nullptr){
        rethrow_exception(eptr);
    }
}