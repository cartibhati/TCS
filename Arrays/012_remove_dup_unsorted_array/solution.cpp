// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<algorithm>
#include <unordered_set>
using namespace std;

vector<int> removedup(vector<int>&nums){
    unordered_set<int>s;
    vector<int>ans;
    for(int x:nums){
        if(s.find(x)==s.end()){
        s.insert(x);
        ans.push_back(x);
        }
    }
    return ans;
}
int main() {
    vector<int>nums={1,1,2,2,2,3,3};
    vector<int>ans=removedup(nums);
    for(int x: ans){
        cout<<x<<" ";
    }
}