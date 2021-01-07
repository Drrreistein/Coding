#include <iostream>
using namespace std;

/**
int main(){
    double num;
    while(cin>>num){
         int sign = num<0 ? -1:1;
         num=num*sign;

        double a=1,b=num;
        if(num<1){a=num;b=1;}

        double x=(a+b)/2;

        while(b-a>0.01){

            if (num-x*x*x<0){
                a=a;b=x;
            }else{
                a=x;b=b;
            }
            x=(a+b)/2;
            
        }

        printf("%0.1f\n",x*sign);

        // cout << x << endl;
    }
    return 0;
}
*/


int main(){

    double num;
    // newton method
    while(cin>>num){
        double x=1;
        double err = x*x*x-num;
        while(err>0.01 || err<-0.01){
            x = (2*x+num/x/x)/3; // Newton method
            err = x*x*x-num;
        }

        printf("%0.1f\n",x);

        // cout << x << endl;
    }
    return 0;
}