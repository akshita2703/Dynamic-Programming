#include<bits/stdc++.h>
using namespace std;
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<int> prev(n+1,0),curr(n+1,0);
    int N=price.size();
    // base case
    for(int n1 =0;n1<=n;n1++){
        prev[n1]=price[0]*n1;
    }
    for(int ind =1;ind<n;ind++){
        for(int n1=0;n1<=n;n1++){
            int notTake = prev[n1];
            int take = INT_MIN;
            int rodlength = ind+1;
            if(rodlength<=n1){
                take = price[ind] +curr[n1-rodlength];
            }
            curr[n1]=max(notTake,take);
        }
        prev=curr;
    }
    return prev[n];
}

int main(){
    vector<int> arr={25,79,59,63,65,6,46,82};
    int n=8;
   
    cout<<cutRod(arr,n);
}