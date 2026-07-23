// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void leftrotatebyk(vector<int>&nums,int k){
    int n=nums.size();
    k%=n;
    
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
    reverse(nums.begin(),nums.end());
}
int main() {
    vector<int>nums={1,2,3,4,5};
    leftrotatebyk(nums,2);
    for(int x:nums){
        cout<<x<<" ";
    }
}