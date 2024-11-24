#include <iostream>
using namespace std;
int main(){
    double celcius , fahrenheit ,kelvin ;
    int choice;
    cout << "enter temp in celcius"<<endl;
    cin >> celcius;
    fahrenheit = (celcius * (9.0/5.0) ) + 32;
    kelvin = celcius +273;
    cout<<"choose:- "<<endl;
    cout<<"1)fahrenheit"<<endl<<"2)kelvin"<<endl;
    cin>>choice;
    if(choice){
     cout<<"temp in fahrenheit = "<<fahrenheit<<endl;
    }
    else if (choice==2){
      cout<<"temp in kelvin = "<<kelvin<<endl;
    }
    else {
        cout<<"enter valid choice"<<endl;
    }
    return 0;

}