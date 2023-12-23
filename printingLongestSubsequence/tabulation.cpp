#include<bits/stdc++.h>
using namespace std;

void longestCommonSubsequence(string text1, string text2) {
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
        int len =dp[m][n];
        string ans = "";
        for(int i =0;i<len;i++){
            ans+='$';
        }
        int index=len-1;
        int i=m;
        int j=n;

        while(i>0&&j>0){
            if(text1[i-1]==text2[j-1]){
                ans[index]=text2[j-1];
                index--;
                i--,j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
        cout << ans;
    }



    int main(){
    string text1 ="abcde";
    string text2= "bdgdek";
    longestCommonSubsequence(text1,text2);
}