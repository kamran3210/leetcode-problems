class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int p = 1;
        for (int i = 0; i < n; i++)
        {
            result[i] = p;
            p *= nums[i];
        }

        p = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            result[i] *= p;
            p *= nums[i];
        }

        return result;
    }
};