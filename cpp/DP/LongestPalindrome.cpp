#include <iostream>
using namespace std;
#include <string>
/**
 * 最长回文子串/最长公共子串
 * 
 * 
*/
int main()
{
    string str;
    while (cin >> str)
    {
        int count = 1, maxLen = 0;
        int len = str.size();

        if (len == 0)
        {
            maxLen = 0;
        }
        else if (len == 1)
        {
            maxLen = 1;
        }
        else
        {
            for (int i = 0; i < len; i++)
            {

                if (i - count >= 1 && str.at(i) == str.at(i - count - 1))
                {
                    count += 2;
                }
                else if (i - count >= 0 && str.at(i) == str.at(i - count))
                {
                    count += 1;
                }
                else
                {
                    count = 1;
                }

                if (count > maxLen)
                {
                    maxLen = count;
                    cout << maxLen << str.substr(i - maxLen + 1, maxLen) << endl;
                }
            }
        }

        cout << maxLen << endl;
    }
    return 0;
}