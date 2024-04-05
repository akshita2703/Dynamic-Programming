
// https://leetcode.com/problems/longest-common-subsequence/description/
// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.

// subsequence -- order hota h continunity se ghnta farak padta


#include<bits/stdc++.h>
using namespace std;

int f(int t,int s, string text1,string text2){
    if(t<0||s<0)return 0;

    // match
    if(text1[t]==text2[s]){
        return 1+f(t-1,s-1,text1,text2);
    }
    return  max(f(t-1,s,text1,text2),f(t,s-1,text1,text2));
}

int longestCommonSubsequence(string text1, string text2) {
    int t=text1.size()-1;
    int s = text2.size()-1;
    return f(t,s,text1,text2);
        
}


int main(){
    int t;
    cin>>t;
    while(t--){
        string text1;
        cin>>text1;
        string text2;
        cin>>text2;
        int ans = longestCommonSubsequence( text1, text2);
        cout<<ans;
    }

    return 0;

}