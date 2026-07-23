#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int sum(vector<int>nums){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
    }
    return sum;
}

int main() {
    vector<int>nums = {1,2,3,4,5};
    cout<<sum(nums);
}