
#include <bits/stdc++.h>
using namespace std;

int fun(vector<int>& arr, int i, int j, vector<vector<int>>& dp){
    
    if(i == j)
        return 0;
        
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    int mini = INT_MAX;
    

    for(int k = i; k<= j-1; k++){
        
        int ans = fun(arr,i,k,dp) + fun(arr, k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
        
        mini = min(mini,ans);
        
    }
    
    return mini;
}


int mcm(vector<int>& arr, int N){
    
    vector<vector<int>> dp(N,vector<int>(N,-1));
    
    int i =1;
    int j = N-1;
    
    
    return fun(arr,i,j,dp);
    
    
}

int main() {
	
	vector<int> arr = {10, 20, 30, 40, 50};
	
	int n = arr.size();
	
	cout<<"The minimum number of operations is "<<mcm(arr,n);
	
	return 0;
}
