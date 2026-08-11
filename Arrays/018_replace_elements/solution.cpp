#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void replaceElements(vector<int>& nums) {
    vector<int> temp = nums; 

    sort(temp.begin(), temp.end());

    unordered_map<int, int> rank;
    int currentRank = 1;

    for (int value : temp) {
        if (rank.find(value) == rank.end()) {
            rank[value] = currentRank++;
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        nums[i] = rank[nums[i]];
    }
}

int main() {
    vector<int> nums = {20, 15, 26, 2, 98, 6};

    replaceElements(nums);

    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}
