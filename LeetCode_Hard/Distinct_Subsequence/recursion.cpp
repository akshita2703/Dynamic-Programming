#include<bits/stdc++.h>
using namespace std;

 int Distinct(string &s, string &t , int i , int j){
        if(j<0) return 1;
        if(i<0) return 0;

       
        if(s[i]==t[j]){
            return  Distinct(s,t,i-1,j-1)+ Distinct(s,t,i-1,j);
        }
        return Distinct(s,t,i-1,j);
}
int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    return  Distinct(s,t,n-1,m-1); 
}
    int main(){
    string text1 ="babgbag";
    string text2= "bag";
    cout<< numDistinct(text1,text2);
}