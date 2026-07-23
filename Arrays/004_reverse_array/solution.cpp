#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> reverse(vector<int>&nums){
    int i=0;
    int n=nums.size();
    int j=n-1;
    while(i<j){
        swap(nums[i],nums[j]);
        i++;
        j--;
    }
    return nums;
}
int main(){
    vector<int>nums={1,2,3,4,5};
    vector<int>ans=reverse(nums);
    for(int x:ans){
        cout<<x<<" ";
    }
}
