#include <iostream>
using namespace std;
int main(){
    float temp;
    cout<<"enter temperature in fahrenheit:";
    cin>>temp;
    double celsius= ((temp-32)*5)/9;
    //int celsius= (5/9)*(temp-32);
    cout<< "temperature in celsius is:"<<celsius;
    return 0;
}