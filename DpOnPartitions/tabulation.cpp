#include <bits/stdc++.h> 
using namespace std;



int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
   int dp[N][N];
   for(int i=1;i<N;i++) dp[i][i]=0;
   for(int i =N-1;i>=0;i--){
       for(int j = i+1;j<N;j++){
           int mini=1e9;
           for(int k=i;k<j;k++){

            int steps = arr[i-1]*arr[k]*arr[j] +dp[i][k]+dp[k+1][j];
            if(steps<mini) mini = steps;
        }
        dp[i][j]= mini;

       }
   }

    return dp[1][N-1];
}

int main()
{
    // Example usage
    vector<int> dimensions = {10, 30, 5, 60};
    int result = matrixMultiplication(dimensions, dimensions.size());
    cout << "Minimum number of multiplications: " << result << endl;

    return 0;
}