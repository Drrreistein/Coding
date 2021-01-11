#include <iostream>
#include <vector>
using namespace std;
/** divide an integer array into two subarrays, so that sums of both subarrays equal.
 *  
 * DFS, Backtrack
*/
bool fiveAndThree(vector<int> &vec, vector<bool> &choose){
    bool res5=false;
    for(int i=0; i<vec.size(); i++){
        if(choose[i]){
            res5 = res5 || (vec[i]%5==0 && vec[i]!=0);
        }
    }
    bool res3 = false;
    for(int i=0; i<vec.size(); i++){
        if(choose[i]){
            res3 = res3 || (vec[i]%3==0 && vec[i]!=0);
        }
    }
    return (res3 && res5);
}

bool dfs(vector<int> &vec, vector<bool> &choose, double add, double sum0)
{
    int n = vec.size();
    if (n == 0)
    {
        return false;
    }
    if (add == sum0 / 2)
    {
        return true;
    }

    for (size_t i = 0; i < n; i++)
    {
        if (!choose[i])
        {
            int tmp = vec[i];
            choose[i] = true;

            if (dfs(vec, choose, add + tmp, sum0))
            {
                vector<bool> choose_reverse=choose;
                for(int i=0;i<n;i++){choose_reverse[i] = !choose[i];}
                if(!fiveAndThree(vec,choose_reverse) && !fiveAndThree(vec,choose)){
                    return true;
                }
                
            }
            choose[i] = false;
            // vec.insert(vec.begin() + i, tmp);
        }
        else
        {
            i++;
        }
    }

    return false;
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> vec(n);
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
            sum += vec[i];
        }
        vector<bool> choose(n, false);
        if(dfs(vec, choose, 0, sum)){
                cout << "true" << endl;
        }else{cout << "false" << endl;}
        
    }
    return 0;
}