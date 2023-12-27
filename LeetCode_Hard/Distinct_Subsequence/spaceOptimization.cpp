#include<bits/stdc++.h>
using namespace std;

  
    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        vector<double> curr(m+1,0),prev(m+1,0);
        prev[0]=curr[0]=1;
        // for(int j=1;j<=m;j++){
        //     dp[0][j]=0;
        // }
        
        for(int i =1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1]){
                    curr[j] = prev[j-1]+prev[j];
                }
                else{
                    curr[j]=prev[j];
                }
                
            }
            prev = curr;
        }

        return (int)prev[m];
        
    }
int main(){
    string text1 ="babgbag";
    string text2= "bag";
    cout<< numDistinct(text1,text2);
}