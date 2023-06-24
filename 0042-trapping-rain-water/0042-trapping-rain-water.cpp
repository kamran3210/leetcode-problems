class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;

        int waterHeight[n];
        waterHeight[0] = height[0];
        for (int x = 1; x < n ; x++)
        {
            waterHeight[x] = max(height[x - 1], waterHeight[x - 1]);
        }

        int ans = 0;
        waterHeight[n - 1] = height[n - 1];
        for (int x = n - 2; x >= 0; x--)
        {
            waterHeight[x] = min(
                max(height[x + 1], waterHeight[x + 1]),
                waterHeight[x]
            );
            ans += max(waterHeight[x] - height[x], 0);
        }

        return ans;
    }
};