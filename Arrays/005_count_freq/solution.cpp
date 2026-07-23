#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, int> f;

void freq(vector<int>& nums) {
    for (int x : nums) {
        f[x]++;
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 2, 1, 4, 2, 5};
    freq(nums);
    for (auto it : f) {
        cout << it.first << " -> " << it.second << endl;
    }
    return 0;
}