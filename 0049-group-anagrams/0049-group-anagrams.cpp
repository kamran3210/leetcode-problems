class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> groups;
        for (auto const& s : strs)
        {
            string str = s;
            sort(str.begin(), str.end());
            groups[str].push_back(s);
        }

        for (auto& p : groups) {
            result.push_back(move(p.second));
        }
        return result;
    }
};