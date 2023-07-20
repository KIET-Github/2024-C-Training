class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int>ps(nums.size(),0);
     ps[0] = nums[0];
        int n = nums.size();
        for(int i =1 ; i < n ;i++){
            ps[i] = ps[i-1]+nums[i];
        }
        int t = ps[0];
        int ans =ps[0] ;
        for(int i = 1 ; i < n ; i++){
             if(ps[i]!=ps[i-1]){
                t++;
                 ans = max(ans , t);
             } else{
              t =0;
             }
        }
        return ans;
    }
};