#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int>ascdesc(vector<int>nums){
    sort(nums.begin(),nums.end());
    int mid = nums.size() / 2;
    sort(nums.begin() + mid, nums.end(), greater<int>());
    
    return nums;
}

int main() {
    vector<int>nums = {8,7,1,6,5,9};
    vector<int>ans = ascdesc(nums);
    for(int x:ans){
        cout<<x<<" ";
    }
}