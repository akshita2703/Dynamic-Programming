#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
      bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();
        vector<bool>prev(n+1,false),curr(n+1,false);
        //base case
        prev[0]=true;
        for(int j=1;j<=n;j++){
            prev[j]=false;
        }
         for(int i=1;i<=m;i++){
            bool flag = true;
            for(int k=1;k<=i;k++){
                if(p[k-1]!='*'){
                    flag=false;
                    break;
                    
                    
                }

            }
            curr[0]= flag;
        }
        for(int i =1;i<=m;i++){
            for(int j=1;j<=n;j++){
               if(p[i-1]==s[j-1]||p[i-1]=='?') curr[j] = prev[j-1];
                else if(p[i-1]=='*') curr[j]=prev[j]|| curr[j-1];
                else curr[j]=false;

            }
            prev=curr;
        }
        return prev[n];
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
