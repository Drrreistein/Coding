#include <iostream>
using namespace std;

int main(){
    int num;
    while(cin>>num){
        int count=0;
        for(int i=0; i<=num; i++){

            if(i%10==0 || i%10==1 || i%10==5 || i%10==6){
                int n=1;
                int tail=0;

                while(tail<=i){
                    if(tail==i){
                        count++;
                        cout << i << "\t";
                        break;
                    }
                    n=n*10;
                    tail=i*i%n;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}

/**
#include <iostream>
#include <string>
using namespace std;

int main(){
    int num;
    while(cin>>num){
        int count = 0;
        for(int i=0; i<=num; i++){
            
            string s1 = to_string(i) ;
            string s2 = to_string(i*i);
            if(s2.find(s1) == s2.size()-s1.size()){
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
*/


/**
#include <iostream>
using namespace std;

int main(){
    int num;
    while(cin>>num){
        int count =0;
        int base=10;
        for(int i=0; i<=num; i++){
            
            if(i%10==0||i%10==1||i%10==5||i%10==6){
                if(i*i%base==i){count++;}
                if(i==base){base*=10;}
            }
            
        }
        cout << count << endl;
    }
    return 0;
}
*/