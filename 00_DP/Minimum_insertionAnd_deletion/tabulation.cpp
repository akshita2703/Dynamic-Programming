//https://www.codingninjas.com/studio/problems/minimum-number-of-deletions-and-insertions_4244510

#include<bits/stdc++.h>
using namespace std;
int lcs(string &s1, string &s2,int n1,int n2){
 
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }

        }
    }
    return dp[n1][n2];

}

int canYouMake(string &s1, string &s2){
    // Write your code here.
    int n1 = s1.size();
    int n2 = s2.size();
    int lcss= lcs(s1,s2,n1,n2);
    return(n1+n2-2*lcss);

}

  int main(){
    string text1 ="abcde";
    string text2= "bdgdek";
    cout<< canYouMake(text1,text2);
}