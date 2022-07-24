#include <stdlib.h>
#include <iostream>
#include <utility>

using namespace std;

class Holder{
    public:
        Holder(int size){
            cout << "Invoking constructor" << endl;
            m_data = new int[size];
            m_size = size;
        }

        Holder(const Holder& h){
            cout << "Invoking copy constructor" << endl;
            m_data = new int[h.m_size];
            copy(h.m_data, h.m_data + h.m_size, m_data);
            m_size = h.m_size;
        }

        Holder& operator=(const Holder& h){
            cout << "Invoking copy assignment" << endl;
            if (&h == this)
                return *this;
            delete[] m_data;
            m_data = new int[h.m_size];
            copy(h.m_data, h.m_data + h.m_size, m_data);
            m_size = h.m_size;
            return *this;
        }

        Holder(Holder&& h){
            cout << "Invoking move constructor" << endl;
            m_data = h.m_data;
            m_size = h.m_size;
            h.m_data = nullptr;
            h.m_size = 0;
        }

        Holder& operator=(Holder&& h){
            cout << "Invoking move assignment" << endl;
            if (&h == this)
                return *this;
            delete[] m_data;

            m_data = h.m_data;
            m_size = h.m_size;

            h.m_data = nullptr;
            h.m_size = 0;

            return *this;
        }

        void whereAmI(){
            cout << "m_data is at: " << m_data << endl;
        }
        ~Holder(){
            delete[] m_data;
        }
    
        int* m_data;
        int m_size;
};

Holder createHolder(int size){
    cout << "createHolder()" << endl;
    Holder h(size);
    h.whereAmI();
    return h;
}

int main(){
    Holder h1(1000);
    h1.whereAmI();
    Holder h2(h1);
    h2.whereAmI();
    Holder h3 = createHolder(2000);
    h3.whereAmI();
    h2 = h3;
    h2.whereAmI();
    h2 = createHolder(500);
    h2.whereAmI();
}