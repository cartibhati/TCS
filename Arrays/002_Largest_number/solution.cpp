#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Finds the largest element in the vector.
 * Note: Preserves the user's original logic including the INT_MIN initialization 
 * and double assignment updates.
 */
int largest(vector<int>& nums) {
    int ans = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > ans) {
            ans = nums[i];
        }
        
        ans = max(ans, nums[i]);
    }
    return ans;
}

int main() {
    vector<int> nums = {4, 3, 5, 67, 2, 78, 8};
    cout << largest(nums);
    return 0;
}