

#include <bits/stdc++.h> 
using namespace std;


    int change(int amount, vector<int>& coins) {
       
        int n = coins.size();
        vector<int> prev(amount+1,0), curr(amount+1,0);

         for(int a=0;a<=amount;a++){
           prev[a]= (a%coins[0]==0);
         }
         for(int ind =1;ind<n;ind++){
            for(int a=0;a<=amount;a++){
                int notTake=prev[a];
                int take =0;
                if(a>=coins[ind]){
                    take = curr[a-coins[ind]];
                }
               curr[a]=notTake+take;
            }
            prev = curr;
         }
        return prev[amount];
    }

int main()
{
    vector<int> num = {265,398,78,46,52};
    int tar = 7754;
    cout<<change(tar,num);
}