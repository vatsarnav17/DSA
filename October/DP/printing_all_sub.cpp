#include<iostream>
#include<vector>
using namespace std;
int solve(int arr[],int n, int i,vector<int> &ds)
{
    if(i>=n){
        for(auto it:ds){
            cout<<it<<" ";
        }
        cout<<endl;
        return 0;
    }
    ds.push_back(arr[i]);
    solve(arr,n,i+1,ds);
    ds.pop_back();
    solve(arr,n,i+1,ds);
    return 0;
}
int main()
{
    int arr[]={3,1,2};
    int n=3;
    vector<int> ds;
    solve(arr,n,0,ds);
    return 0;
}