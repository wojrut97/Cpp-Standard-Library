#include <iostream>
#include <chrono>

using namespace std;

int main(){
    auto start = chrono::system_clock::now();
    while(true){
        auto diff = chrono::system_clock::now() - start;
        auto sec = chrono::duration_cast<chrono::seconds>(diff);
        cout << "\rThis program runs: " <<  sec.count() << " seconds";
    }
}