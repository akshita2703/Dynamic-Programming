#include<bits/stdc++.h>
using namespace std;

int Dist(int i , int j,string &s1, string &s2 ){
    if(i<0)return j+1;
    if(j<0)return i+1;
    if(s1[i]==s2[j]) return Dist(i-1,j-1,s1,s2);
    return 1+min(Dist(i,j-1,s1,s2),min(Dist(i-1,j-1,s1,s2),Dist(i-1,j,s1,s2)));

}
int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    return Dist(n-1,m-1,word1,word2);
    
}
int main()
{
    string text1 ="babgbag";
    string text2= "bag";
    cout<< minDistance(text1,text2);
}