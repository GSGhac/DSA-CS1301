#include <iostream>
using namespace std;
class conversion {
    public:
        double celsius (int temp) {
        return ((temp-32)*5)/9;
        };
    private:
        float temp;
};

int main(){
    float temp;
    cout<<"enter temperature in fahrenheit:";
    cin>>temp;
    cout<<"temperature in celsius is:";
    conversion c1;
    cout<<c1.celsius(temp);
    return 0;
};