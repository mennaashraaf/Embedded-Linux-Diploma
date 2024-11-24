#include <iostream>
using namespace std;
class ParentMember {
    public:
 ParentMember(){
    cout<<"construtor parent member"<<endl;
 }
 ~ParentMember(){
    cout<<"destructor parent member"<<endl;
 }
};
class Parent {
    public:
    ParentMember mp;
    Parent(){
        cout<<"constructor parent"<<endl;
    }
    ~Parent() {
        cout<<"destructor parent"<<endl;
    }
};
class Son : public Parent {
    public:
    Son(){
        cout<<"son constructor"<<endl;
    }
    ~Son(){
        cout<<"son destructor"<<endl;
    }
};

int main(){
    Parent *p1;
    Son s1;
    p1=&s1;
    return 0;
}