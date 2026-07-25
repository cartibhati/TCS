// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
using namespace std;

int maxSubarrayProduct(vector<int>nums){
    int ans=nums[0];
    int maxend=nums[0];
    int minend=nums[0];
    for(int i=1;i<nums.size();i++){
        int v1=nums[i];
        int v2=maxend*nums[i];
        int v3=minend*nums[i];
        
        maxend=max(v1,max(v2,v3));
        minend=min(v1,min(v2,v3));
        
        ans=max(ans,max(maxend,minend));
    }
    return ans;
}
int main(){
    vector<int>nums={1,2,-3,0,-4,-5};
    cout<<maxSubarrayProduct(nums);
}
