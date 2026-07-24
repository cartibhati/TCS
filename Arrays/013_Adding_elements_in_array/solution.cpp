// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<algorithm>
#include <unordered_set>
using namespace std;

void insertbeginning(vector<int> &v, int n){
    v.insert(v.begin(),n);
}
void insertending(vector<int> &v,int n){
    v.push_back(n);
}
void insertatpos(vector<int> &v,int n,int k){
    v.insert(v.begin()+k, n);
}
int main() {
    vector<int>nums={1,2,3,4,5};
    insertbeginning(nums,6);
    insertending(nums,7);
    insertatpos(nums,8,4);
    for(int x: nums){
        cout<<x<<" ";
    }
}