class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string& token : tokens) {
            if (token == "+") {
                int s2 = st.top();
                st.pop();
                int s1 = st.top();
                st.pop();
                st.push(s1 + s2);
            } else if (token == "-") {
                int s2 = st.top();
                st.pop();
                int s1 = st.top();
                st.pop();
                st.push(s1 - s2);
            } else if (token == "*") {
                int s2 = st.top();
                st.pop();
                int s1 = st.top();
                st.pop();
                st.push(s1 * s2);
            } else if (token == "/") {
                int s2 = st.top();
                st.pop();
                int s1 = st.top();
                st.pop();
                st.push(s1 / s2);
            } else {
                st.push(stoi(token));
            }
            // cout << token << ": " << st.top() << "\n";
        }
        // cout << "\n";
        return st.top();
    }
};