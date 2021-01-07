// #include "../debug_tools/DisplayData.h"
#include "TwoSum.h"
#include "MaxArea.h"
#include "ThreeSum.h"
#include "ThreeSumClosest.h"
#include "StrStr.h"
#include "TrappingRainWater.h"



#include "../debug_tools/add_header.h"
using namespace std;

bool myfunction (int i,int j);

int main()
{
    cout << "#------------------- q0: two sum " << endl;
    vector<int> q0_nums = {2, 7, 11, 15};
    TwoSum q0;
    DisplayVector(q0.solu1(q0_nums, 9));
    DisplayVector(q0.solu2(q0_nums, 9));
    DisplayVector(q0.solu3(q0_nums, 9));

    cout << "#------------------- q1: maximal area of container " << endl;
    vector<int> height={1, 8, 6, 2, 5, 4, 8, 3, 7};
    height={1,2,4,3};
    MaxArea q1;
    DisplayVector(height);
    cout <<"max area: " << q1.solu1(height) << endl;
    cout <<"max area: " << q1.solu2(height) << endl;

    // test algorithm: sort 
    sort(height.begin(),height.end(), myfunction);
    // sort(height.begin(),height.end());
    DisplayVector(height);

    cout << "#------------------- q2: three Sum " << endl;
    vector<int> nums = {-1,0,1,2,-1,-4};
    ThreeSum q2;
    DisplayMatrix(q2.solu1(nums));
    DisplayMatrix(q2.solu2(nums));
    DisplayMatrix(q2.solu3(nums));

    
    cout << "#------------------- q3: three Sum closest " << endl;
    nums = {-1,2,1,-4};
    nums = {-101,-98,-2,-1};
    ThreeSumClosest q3;
    int target = 1;
    cout << "q3: " << q3.solu1(nums, target) << endl;

    cout << "#------------------- q4 : substring finder " <<endl;
    string str1 = "hello";
    str1 = "lll";
    string str2 = "l";
    StrStr q4;
    cout <<"location: " << q4.solu2(str1, str2) <<endl;
    // cout <<"location: " << q4.solu3(str1, str2) <<endl;

    
    cout << "#------------------- q5: trapping rain water " << endl;
    nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    TrappingRainWater q5;
    DisplayVector(nums, "trap");
    cout << "Water Trapped: " << q5.solu1(nums) << endl; // brute force
    cout << "Water Trapped: " << q5.solu1(nums) << endl; // two pointers


    return 0;
}
// bool myfunction (int i,int j) { return (i<j); } // descen<ing sort


