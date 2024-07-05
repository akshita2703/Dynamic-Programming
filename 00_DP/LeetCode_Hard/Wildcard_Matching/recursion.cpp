#include <iostream>

class Solution {
public:
    bool fun(int i, int j, std::string s, std::string p) {
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
        if (p[i] == s[j] || p[i] == '?') return fun(i - 1, j - 1, s, p);
        if (p[i] == '*') return fun(i - 1, j, s, p) || fun(i, j - 1, s, p);
        return false;
    }

    bool isMatch(std::string s, std::string p) {
        int n = s.size();
        int m = p.size();
        return fun(m - 1, n - 1, s, p);
    }
};

int main() {
    Solution solution;

    // Example usage
    std::cout << std::boolalpha;  // to print 'true' or 'false' instead of '1' or '0'
    std::cout << solution.isMatch("aa", "a") << std::endl;        // Output: false
    std::cout << solution.isMatch("aa", "*") << std::endl;       // Output: true
    std::cout << solution.isMatch("cb", "?a") << std::endl;      // Output: false
    std::cout << solution.isMatch("adceb", "*a*b") << std::endl;  // Output: true
    std::cout << solution.isMatch("acdcb", "a*c?b") << std::endl; // Output: false

    return 0;
}
