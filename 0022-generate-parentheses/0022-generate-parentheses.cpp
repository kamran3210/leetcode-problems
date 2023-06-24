class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;

        function<void(int, int, string)> f;
        f = [n, &res, &f](int open, int closed, string str) -> void {
            if (open == n && open == closed) return res.push_back(str);
            if (open < n) f(open + 1, closed, str + '(');
            if (closed < open) f(open, closed + 1, str + ')');
        };

        f(0, 0, "");
        return res;
    }
};