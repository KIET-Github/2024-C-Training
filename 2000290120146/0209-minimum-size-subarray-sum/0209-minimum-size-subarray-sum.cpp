class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int v = INT_MAX;
         int ans = 0;
         int i  =0 ;
         int  j = 0;
         while(j<nums.size()){
             ans +=nums[j];
             if(ans>= target){
               
                 while(ans>= target && i<=j){
                     v = min(v , j-i+1);
                     ans -=nums[i];
                     i++;
                 }
             }
             j++;

         }
         if(v!= INT_MAX) return v;
         return 0;
    }
};