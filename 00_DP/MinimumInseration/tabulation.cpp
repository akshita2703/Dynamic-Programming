#include<bits/stdc++.h>
using namespace std;

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        // Initialize a 2D array to store the lengths of LCS for subproblems
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Build the dp array bottom-up
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // The result is stored in the bottom-right cell of the dp array
        return dp[m][n];
    }
    int longestPalindromeSubseq(string s) {
        string t =s;
        reverse(t.begin(),t.end());
        return longestCommonSubsequence(s,t); 
    }
      int minInsertions(string s) {
        return (s.size() - longestPalindromeSubseq(s));
        
    }
int main(){
    
    string text2= "madame";
    cout << minInsertions(text2);
}
