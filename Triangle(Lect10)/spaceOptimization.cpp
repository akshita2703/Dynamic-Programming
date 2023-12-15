
//Memoization  


#include<bits/stdc++.h>
using namespace std;
//tabulation

int minimumPathSum(vector<vector<int>>&triangle){
    
    int n = triangle.size();
    vector<int>front(n,0) , curr(vector<int>(n,0)) ;
    // intialize a 2d vector for dp 
    for(int j =0; j<n;j++){
        front[j] = triangle[n-1][j];

    }
    for (int i = n-2; i>=0; i--)
    {
        for(int j =i;j>=0;j--){
            int d = triangle[i][j]+front[j];
            int dg = triangle[i][j]+front[j+1];
            curr[j]=min(d,dg);
        }
        front = curr;
    }
    

   return front[0];
}

int main() {
    
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    int result = minimumPathSum(triangle);
    cout << "Minimum path sum: " << result <<endl;

    return 0;
}