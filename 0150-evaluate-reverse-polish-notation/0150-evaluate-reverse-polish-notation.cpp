class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for (string& token : tokens) {
            if (token == "+") {
                auto p = pop2(st);
                st.push(to_string(p.first + p.second));
            } else if (token == "-") {
                auto p = pop2(st);
                st.push(to_string(p.first - p.second));
            } else if (token == "*") {
                auto p = pop2(st);
                st.push(to_string(p.first * p.second));
            } else if (token == "/") {
                auto p = pop2(st);
                st.push(to_string(p.first / p.second));
            } else {
                st.push(token);
            }
            // cout << token << ": " << st.top() << "\n";
        }
        // cout << "\n";
        return stoi(st.top());
    }
private:
    pair<int, int> pop2(stack<string>& st) {
        string s2 = st.top();
        st.pop();
        string s1 = st.top();
        st.pop();
        return pair(stoi(s1), stoi(s2));
    }
};