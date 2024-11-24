#include <iostream>
#include <stdexcept>
using namespace std;
class Time{
public:
int hour,minute,second;
Time(int h , int m , int s):hour(h) ,minute(m) ,second(s){}

Time operator+=(const Time &t){
    this->hour += t.hour;
    this->minute+=t.minute;
    this->second+=t.second;
    return *this;

}

};
int main() {
   Time t1(1,2,3);
   Time t2(1,2,3);
   t1+=t2;
   cout<<t1.hour<<endl;

   
    return 0;
}