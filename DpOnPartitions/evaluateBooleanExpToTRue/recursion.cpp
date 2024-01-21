
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1000000007;
 int f(int i, int j ,int isTrue,string& exp){
        if(i>j)return 0;
        if(i==j){
            if(isTrue) return exp[i]=='T';
            else {return exp[i] == 'F';}
        }
        ll ways=0;
        for(int ind = i+1; ind<=j-1;ind+=2){
            ll lt = f(i,ind-1,1,exp);
            ll lf = f(i,ind-1,0,exp);
            ll rt = f(ind+1,j,1,exp);
            ll rf = f(ind+1,j,0,exp);

            if(exp[ind]=='&'){
                if(isTrue) ways = (ways+(rt*lt)%mod)%mod;
                else ways = (ways+(rt*lf)%mod+(rf*lf)%mod+(rf*lt)%mod)%mod;
            }
            else if(exp[ind]=='|'){
                if(isTrue) ways = (ways+(rt*lf)%mod +(rt*lt)%mod+(rf*lt)%mod)%mod;
                else{ways=(ways+(rf*lf)%mod)%mod;}
            }
            else{
                //t^t=f,f^f=f, t^f=t,f^t=t
                if(isTrue) ways=(ways+(rt*lf)%mod+(lt*rf)%mod)%mod;
                else{
                    ways=(ways+(rt*lt)%mod+(lf*rf)%mod)%mod;
                }
            }

            
        }
        
        return ways;
    }

int evaluateExp(string & exp) {
    // Write your code here.
    int n = exp.size();
     return f(0,n-1,1,exp);
}