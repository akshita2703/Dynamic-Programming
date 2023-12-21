

#include <bits/stdc++.h> 
using namespace std;

 int f(int ind,vector<int>& coins, int amount)
    {
        if(ind==0){
           
             return( amount%coins[0])==0;
        
          
        
        }
        int notTake =f(ind-1,coins,amount);
        int take = 0;
        if(coins[ind]<=amount){
            take =f(ind,coins,amount-coins[ind]);
        }
        return notTake+take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return f(n-1,coins,amount);
    }

    int main(){
    vector<int> num = {265,398,78,46,52};
    int tar = 7754;
    cout<<change(tar,num);
}