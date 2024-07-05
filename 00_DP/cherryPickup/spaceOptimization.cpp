#include<bits/stdc++.h>
using namespace std;

//1d--> two varaible 
// 2d -->1d dp
// 3d--> 2d
int cherryPickup(vector<vector<int>>&grid) {
    int n = grid.size();
    int m= grid[0].size();
    vector<vector<int>>front(m,vector<int>(m,0));
    vector<vector<int>>curr(m,vector<int>(m,0));
   
    // Base Case
    for(int j1 =0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2){
                front[j1][j2] = grid[n-1][j1];
            }
            else{
                front[j1][j2] = grid[n-1][j1]+grid[n-1][j2];
            }
        }
    }

    // express all other state
    for(int i = n-2;i>=0;i--){
        for(int j1 = 0;j1<m;j1++){
            for(int j2 = 0;j2<m;j2++){
                int maxi=-1e8;
                for(int dj1 = -1;dj1<=+1;dj1++){
                    for(int dj2 = -
                    1;dj2<=+1;dj2++){
                        int value =0;
                        if(j1==j2){
                            value = grid[i][j1];
                        }
                        else{
                            value = grid[i][j1]+grid[i][j2];
                        }
                        if(j1+dj1>=0&& j1+dj1<m &&j2+dj2>=0&& j2+dj2<m){
                            value +=front[j1+dj1][j2+dj2];
                        }
                        else{
                            value+=-1e8;
                        }
                        maxi = max(maxi,value);
                    }
                }
                curr[j1][j2]=maxi;
            }
        }
        front = curr;
    }
    return front[0][m-1];

        
        
}



int main() {
    
    vector<vector<int>> grid = {
       {3,1,1},{2,5,1},{1,5,5},{2,1,1}
    };

    int result = cherryPickup(grid);
    cout << "Maximum path sum: " << result <<endl;

    return 0;
}
