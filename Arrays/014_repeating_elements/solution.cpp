// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
using namespace std;

vector<int> repeating_elements(vector<int>& nums) {
    unordered_map<int, int> f;
    vector<int> ans;
    for (int x : nums) {
        f[x]++;
    }
    for (auto x : f) {
        if (x.second > 1) {
            ans.push_back(x.first);
        }
    }
    return ans;
}

int main() {
    vector<int>nums={1,1,2,3,4,4,5,2};
    vector<int>ans=repeating_elements(nums);
    for(int x:ans){
        cout<<x<<" ";
    }
}