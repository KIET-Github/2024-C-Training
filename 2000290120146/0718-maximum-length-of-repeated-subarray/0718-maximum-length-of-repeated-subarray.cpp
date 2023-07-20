class Solution {
public:
   int f( int i , int j , vector<int> &nums1 , vector<int> & nums2 ){
       if(i==nums1.size() || j== nums2.size()) return 0;
        if(nums1[i]==nums2[j]){
           return f(i+1 , j+1 , nums1 , nums2);

        } 
            return max(f(i , j+1 , nums1 , nums2) , f(i+1 , j , nums1 , nums2));
        
     

   }
    int findLength(vector<int>& text1, vector<int>& text2) {
           int m = text1.size();
        int n = text2.size();
        int ans = INT_MIN;
        vector<vector<int>>dp(m+1 , vector<int>(n+1 , 0));
        for(int i = 1 ; i<= m ;i++){
            for(int j = 1 ; j <= n ; j++){

                 if(text1[i-1]== text2[j-1]) {  dp[i][j]= 1+dp[i-1][j-1]; }
                  ans = max( ans  , dp[i][j]);
        
            }
        }
        return ans;
          
        
    }
};