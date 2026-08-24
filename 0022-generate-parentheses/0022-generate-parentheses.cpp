class Solution {
public:
    vector<string> generateParenthesis(int n) {
 vector<string> ans;

        function<void(int, int, string)> solve = [&](int open, int close, string s) {
            if (s.size() == 2 * n) {
                ans.push_back(s);
                return;
            }

            if (open < n)
                solve(open + 1, close, s + "(");

            if (close < open)
                solve(open, close + 1, s + ")");
        };

        solve(0, 0, "");

        return ans;
    }
};