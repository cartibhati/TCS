// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

int avg(vector<int>nums){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
    }
    int n=nums.size();
    int avg=sum/n;
    
    return avg;
}
int main() {
    vector<int>nums={1,2,3,4,5};
    cout<<avg(nums);
}