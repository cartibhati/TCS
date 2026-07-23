// Online C++ compiler to run C++ program online
#include <iostream>
#include<climits>
#include<vector>
using namespace std;
int smallest(vector<int>&nums){
    int ans=INT_MAX;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<ans)
        ans=nums[i];
        
        ans=min(ans,nums[i]);
    }
    return ans;
}
int main() {
    vector<int>nums={4,3,5,67,2,78,8};
    cout<<smallest(nums);
}
