class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> isFlipped(n, 0); // Track flips at each index
        int flipCount = 0; // Total number of flips
        int flipped = 0; // Current state (0 means unflipped, 1 means flipped)

        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                flipped ^= isFlipped[i - k]; // Remove the effect of the flip that's out of the window
            }

            // If the current bit is not what we want (1) after accounting for flips, flip it
            if (nums[i] == flipped) {
                if (i + k > n) { // If we cannot flip a subarray of length k from here, return -1
                    return -1;
                }
                isFlipped[i] = 1; // Mark a flip starting at index i
                flipCount++;
                flipped ^= 1; // Toggle the flip state
            }
        }

        return flipCount;
    }
};