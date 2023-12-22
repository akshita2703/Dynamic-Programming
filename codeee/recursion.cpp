


#include<bits/stdc++.h>

using namespace std;

int f( int ind, int prod, int l,vector<int>&arr,int c){
    if(ind==0){
        return prod>=(prod*arr[0])/l;
    }
    int notTake = 0+f(ind-1,prod,l,arr,c);
    int take = INT_MIN;
    if(prod>=(int)prod*arr[ind]/l ){
         take = 1+f(ind-1, prod*arr[ind]/l,l*l+1,arr,c+1);

    }
    
    return max(notTake,take);
}
int main(){
    vector<int> arr={2,3,4};
    int n=3;
    int prod = 1;
    int l=1;
    cout<<f(n-1,prod,l,arr,0);
}