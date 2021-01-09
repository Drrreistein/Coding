#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    
    int n;
    
    while(cin >>n){
        int num,count1=0, count2=0;
        double sum=0.0;
        for(int i=0; i<n; i++){
            cin >> num;
            if(num>0){
                count2++;
                sum += num;
            }else if(num<0){
                count1++;
            }
        }
        cout << count1 << " " << fixed << setprecision(1) <<sum/count2 << endl;
    }
    

    return 0;
}