/**
 * https://www.nowcoder.com/practice/2baa6aba39214d6ea91a2e03dff3fbeb?tpId=37&tags=&title=&diffculty=0&judgeStatus=0&rp=1

input:
// D:\zwtymj\xccb\ljj\cqzlyaszjvlsjmkwoqijggmybr 645
// E:\je\rzuwnjvnuz 633
// C:\km\tgjwpb\gy\atl 637
// F:\weioj\hadd\connsh\rwyfvzsopsuiqjnr 647
// E:\ns\mfwj\wqkoki\eez 648
// D:\cfmwafhhgeyawnool 649
// E:\czt\opwip\osnll\c 637
// G:\nt\f 633
// F:\fop\ywzqaop 631
// F:\yay\jc\ywzqaop 631

*/

#include <iostream>

#include <string>
#include <map>
#include <queue>
using namespace std;

int main(){
    string str;
    map<string, int> mp;
    queue<string> qu;
    while(getline(cin, str)){
        int len=str.size();
        for(int i=len-1; i>=0; i--){
            if(str[i]=='\\'){
                if(mp[str.substr(i+1)]==0){
                   qu.push(str.substr(i+1));
                    if(qu.size()>8){qu.pop();}
               }
                
                mp[str.substr(i+1)]++;
                break;
            }
        }

    }
    while(!qu.empty()){
        //cout <<qu.size()<< endl;
        cout << qu.front() << " " << mp[qu.front()] << endl;
        qu.pop();
    }
    return 0;
}