// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int removedup(vector<int>&nums){
    int i=0;
    if(nums.empty()) return 0;
    for(int j=1;j<nums.size();j++){
        if(nums[i]!=nums[j]){
            i++;
            nums[i]=nums[j];
        }
    }
    return i+1;
}
int main() {
    vector<int>nums={1,1,2,2,2,3,3};
    cout<<removedup(nums);
}