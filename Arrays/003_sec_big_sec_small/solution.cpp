// Online C++ compiler to run C++ program online
#include <iostream>
#include<climits>
#include<vector>
using namespace std;
int secsmall(vector<int>& nums){
    int small = INT_MAX;
    int secsmall = INT_MAX;

    for(int x : nums){
        if(x < small){
            secsmall = small;
            small = x;
        }
        else if(x > small && x < secsmall){
            secsmall = x;
        }
    }
    return secsmall;
}
int secbig(vector<int>& nums){
    int big = INT_MIN;
    int secbig = INT_MIN;

    for(int x : nums){
        if(x > big){
            secbig = big;
            big = x;
        }
        else if(x < big && x > secbig){
            secbig = x;
        }
    }
    return secbig;
}
int main() {
    vector<int>nums={4,3,5,67,2,78,8};
    cout<<secsmall(nums);
    cout<<endl;
    cout<<secbig(nums);
}