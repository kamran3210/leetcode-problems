class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        unordered_set<int> set(nums.begin(), nums.end());
        for (int n : nums) {
            if (!set.count(n - 1)) {
                int length = 1;
                while (set.count(n + length)) {
                    length++;
                }
                result = max(result, length);
            }
        }
        return result;
    }
};