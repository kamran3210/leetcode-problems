class Solution {
public:
    bool isValid(string str) {
        unordered_map<char, char> pairs = {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };
        stack<char> s;
        for (char& c : str) {
            if (s.size() > 0 && pairs[c] == s.top()) s.pop();
            else s.push(c);
        }
        return s.size() == 0;
    }
};