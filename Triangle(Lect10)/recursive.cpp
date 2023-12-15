#include<bits/stdc++.h>
using namespace std;
int f(int i , int j,vector<vector<int>>&triangle,int n){
    if(i==n-1){
        return triangle[n-1][j];
    }
    int d = triangle[i][j]+f(i+1,j,triangle,n);
    int dg = triangle[i][j]+f(i+1,j+1,triangle,n);
    return min(d,dg);

}

int minimumPathSum(vector<vector<int>>&triangle){
    int n = triangle.size();

    return f(0,0,triangle,n);
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