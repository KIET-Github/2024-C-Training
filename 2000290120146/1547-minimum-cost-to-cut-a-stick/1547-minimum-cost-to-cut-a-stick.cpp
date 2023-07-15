class Solution {
public:
    long f(int i , int j , vector<int>&cuts  , vector<vector<int>>&dp){
        if(i>j) return 0;
        long  mini = LONG_MAX;
        if(dp[i][j]!= -1) return dp[i][j];
        for(int ind = i ; ind<=j ;ind++ ){
          long step  = cuts[j+1]-cuts[i-1] +f( i  , ind -1 , cuts , dp) + f(ind+1  ,  j , cuts , dp);
            mini = min(step , mini);
        }
        return dp[i][j]= mini ; 
    }
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>>dp(cuts.size()+1 , vector<int>(cuts.size()+1 , -1));
        cuts.push_back(n);
        cuts.insert(cuts.begin() , 0);
        sort(cuts.begin() , cuts.end());
        return f( 1 , cuts.size()-2 , cuts , dp);
        
    }
};