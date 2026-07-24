// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int median(vector<int>&nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int mid=n/2;
    return nums[mid];
}
int main() {
    vector<int>nums={2,4,1,3,5};
    cout<<median(nums);
}