#include <iostream>
using namespace std;
class Base {
    public:
    virtual void display() {
        cout<<"base"<<endl;
    }
};
class Derived1 : public Base {
    public:
    virtual void display(int x) {
        cout<<"Derived1 "<<x<<endl;
    }
};
class Derived2 : public Derived1 {
    public:
    void display() {
        cout<<"Derived2"<<endl;
    }
};
int main() {
    
    Derived1 d1;
    Derived2 d2;
    Base* ptr1 = &d1;
    Base* ptr2 = &d2;
    ptr1->display();
    ptr2->display();
    //ptr1->display(5); error too many arguments
    d1.display(5);
    //d1.display(); error too few arguments
    return 0;
}