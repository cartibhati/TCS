// Online C++ compiler to run C++ program online
#include <iostream>
#include<climits>
#include<vector>
using namespace std;
int largest(vector<int>&nums){
    int ans=INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>ans)
        ans=nums[i];
        
        ans=max(ans,nums[i]);
    }
    return ans;
}
int main() {
    vector<int>nums={4,3,5,67,2,78,8};
    cout<<largest(nums);
}