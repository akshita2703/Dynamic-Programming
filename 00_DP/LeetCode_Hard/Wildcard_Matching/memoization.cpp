#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool fun(int i, int j, string s, string p, vector<vector<int>>& dp) {
        // base case 
        if (i < 0 && j < 0) return true;
        if (i < 0 && j >= 0) return false;
        if (i >= 0 && j < 0) {
            for (int k = 0; k <= i; k++) {
                if (p[k] != '*') {
                    return false;
                }
            }
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (p[i] == s[j] || p[i] == '?') return dp[i][j] = fun(i - 1, j - 1, s, p, dp);
        if (p[i] == '*') return dp[i][j] = fun(i - 1, j, s, p, dp) || fun(i, j - 1, s, p, dp);
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return fun(m - 1, n - 1, s, p, dp);
    }
};

int main() {
    Solution solution;

    // Example usage
    cout << boolalpha;  // to print 'true' or 'false' instead of '1' or '0'
    cout << solution.isMatch("aa", "a") << endl;        // Output: false
    cout << solution.isMatch("aa", "*") << endl;       // Output: true
    cout << solution.isMatch("cb", "?a") << endl;      // Output: false
    cout << solution.isMatch("adceb", "*a*b") << endl;  // Output: true
    cout << solution.isMatch("acdcb", "a*c?b") << endl; // Output: false

    return 0;
}
