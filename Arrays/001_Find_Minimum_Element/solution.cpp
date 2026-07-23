#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Finds the smallest element in the vector.
 * Note: Preserves the user's original logic including the INT_MAX initialization 
 * and double assignment updates.
 */
int smallest(vector<int>& nums) {
    int ans = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < ans) {
            ans = nums[i];
        }
        
        ans = min(ans, nums[i]);
    }
    return ans;
}

int main() {
    vector<int> nums = {4, 3, 5, 67, 2, 78, 8};
    cout << smallest(nums);
    return 0;
}
