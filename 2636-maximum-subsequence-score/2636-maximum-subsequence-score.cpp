static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<pair<int, int>> pairs;

        for (int i = 0; i < nums1.size(); i++)
            pairs.push_back(make_pair(nums1[i], nums2[i]));
            
        auto cmp = [](pair<int, int>& left, pair<int, int>& right) { return left.second > right.second; };
        sort(pairs.begin(), pairs.end(), cmp);
        
        long long ans = 0;
        long long topKSum = 0;
        priority_queue<int, vector<int>, greater<int>> topK;
        for (int i = 0 ; i < k; i++)
        {
            topK.push(pairs[i].first);
            topKSum += pairs[i].first;
        }
        ans = topKSum * pairs[k - 1].second;
        

        for (int i = k; i < nums1.size(); i++)
        {
            topKSum -= topK.top();
            topK.pop();
            topKSum += pairs[i].first;
            topK.push(pairs[i].first);
            ans = max(ans, topKSum * pairs[i].second);
        }

        return ans;
    }
};