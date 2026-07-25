// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
using namespace std;

void findSymmetricPairs(vector<pair<int,int>>&arr){
    unordered_map<int,int>mp;
    for(auto p:arr){
        int first=p.first;
        int second= p.second;
        
        if(mp.find(second) != mp.end() && mp[second] == first){
            cout<<'('<<second<<','<<first<<')'<<','<<'('<<first<<','<<second<<')'<<endl;
        }
        else
        mp[first]=second;
    }
}
int main() {
    vector<pair<int, int>> arr = {
        {1,2},
        {3,4},
        {2,1},
        {5,4},
        {4,5}
    };

    findSymmetricPairs(arr);

    return 0;
}

