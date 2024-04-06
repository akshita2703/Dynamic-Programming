#include<bits/stdc++.h>
using namespace std;

void insert(vector<int>&v , int temp){
    if(v.size()==0 || v[v.size()-1]<=temp){
        v.push_back(temp);
        return ;
    }
    int val = v[v.size()-1];
    v.pop_back();
    insert(v,temp);
    v.push_back(val);
    return ;
}

void sort(vector<int>&v){
    if(v.size()==1)return ;
    int temp = v[v.size()-1];
    v.pop_back();
    sort(v);
    insert(v,temp);
    return ;
}



int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i =0;i<n;i++){
        int k;
        cin>>k;
        v.push_back(k);
    }
    sort(v);
    for(int i =0;i<n;i++){
        
        cout<< v[i] << " ";
    }
    return 0;

}