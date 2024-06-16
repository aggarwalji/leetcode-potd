class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
          long long miss = 1;  // This represents the smallest number that cannot be formed.
    int patches = 0;     // To count the number of patches added.
    int i = 0;           // Index to iterate through nums.

    while (miss <= n) {
        if (i < nums.size() && nums[i] <= miss) {
            miss += nums[i];
            i++;
        } else {
            miss += miss;
            patches++;
        }
    }

    return patches;

    }
};