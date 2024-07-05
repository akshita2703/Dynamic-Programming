#include<bits/stdc++.h>
using namespace std;

int f(int ind , int n,vector<int>&price){
    if(ind==0) return(price[0]*n);
    int notTake = f(ind-1,n,price);
    int take = INT_MIN;
    int rodlength = ind+1;
    if(rodlength<=n){
        take = price[ind] +f(ind , n-rodlength,price);
    }
    return max(notTake,take);

}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    int N=price.size();
    return f(N-1,n,price);
}


int main(){
    vector<int> arr={3,5,8,9,10,17,17,20};
    int n=8;
   
    cout<<cutRod(arr,n);
}