#include <iostream>
using namespace std;
class perfectSquare {
 float length;
 public:
    perfectSquare(const perfectSquare &ps) {
        this->length=ps.length;
    }
 void printArea(){
    float area = length * length;
  cout<<"area = "<<area<<endl;
 }
};
void fun(int *ptr){

}

int main() {
    //perfectSquare a(10.5);
    //a.printArea();
    fu({1,2,3});

    return 0;
}