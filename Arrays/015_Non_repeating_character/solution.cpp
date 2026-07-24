// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
using namespace std;

vector<int> non_repeating_elements(vector<int>& nums) {
    unordered_map<int, int> f;
    vector<int> ans;
    for (int x : nums) {
        f[x]++;
    }
    for (auto x : f) {
        if (x.second <= 1 ) {
            ans.push_back(x.first);
        }
    }
    return ans;
}

int main() {
    vector<int>nums={1,2,-1,1,3,1};
    vector<int>ans=non_repeating_elements(nums);
    for(int x:ans){
        cout<<x<<" ";
    }
}