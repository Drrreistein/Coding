// #include "../debug_tools/DisplayData.h"
#include "MaxArea.h"
#include <iostream>
#include "DebugMode.h"
using namespace std;

int main()
{
    cout << "#------------------- q1: maximal area of container " << endl;
    vector<int> height={1, 8, 6, 2, 5, 4, 8, 3, 7};
    height={1,2,4,3};
    MaxArea q1;
    DisplayVector(height);
    cout <<"max area: " << q1.solu1(height) << endl;
    cout <<"max area: " << q1.solu2(height) << endl;

    return 0;
}


