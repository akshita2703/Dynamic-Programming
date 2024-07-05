#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
     bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        //base case
        dp[0][0]=true;
        for(int j=1;j<=n;j++){
            dp[0][j]=false;
        }
         for(int i=1;i<=m;i++){
            bool flag = true;
            for(int k=1;k<=i;k++){
                if(p[k-1]!='*'){
                    flag=false;
                    break;
                    
                    
                }

            }
            dp[i][0]= flag;
        }
        for(int i =1;i<=m;i++){
            for(int j=1;j<=n;j++){
               if(p[i-1]==s[j-1]||p[i-1]=='?') dp[i][j] = dp[i-1][j-1];
                else if(p[i-1]=='*') dp[i][j]=dp[i-1][j]|| dp[i][j-1];
                else dp[i][j]=false;

            }
        }
        return dp[m][n];
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
