#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

/**
 * Finds the minimum element in a given vector of integers.
 * 
 * @param nums A constant reference to a vector of integers.
 * @return The smallest integer in the vector.
 * @throws std::invalid_argument if the input vector is empty.
 */
int findMinimumElement(const std::vector<int>& nums) {
    if (nums.empty()) {
        throw std::invalid_argument("Array/Vector cannot be empty.");
    }
    
    // Initialize mini with the first element of the array.
    // This avoids using hardcoded values like INT_MAX, which is safer
    // and cleaner if the array contains INT_MAX as its only element.
    int minVal = nums[0];
    
    // Single-pass scan to find the smallest element.
    // Starting from index 1 since index 0 is already the initial minVal.
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] < minVal) {
            minVal = nums[i];
        }
    }
    
    return minVal;
}

int main() {
    // Example test case
    std::vector<int> nums = {4, 3, 5, 67, 2, 78, 8};
    
    try {
        int result = findMinimumElement(nums);
        std::cout << "The minimum element in the array is: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
