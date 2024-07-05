#include <bits/stdc++.h> 
using namespace std;x

int f(int i , int j, vector<int>&arr){
    if(i==j)return 0;
    int mini = 1e8;
    for(int k=i;k<j;k++){
        int steps = arr[i-1]*arr[k]*arr[j] +f(i,k,arr)+f(k+1,j,arr);
        if(steps<mini) mini = steps;
    }
    return mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    return f(1,N-1,arr);
}
int main(){

}