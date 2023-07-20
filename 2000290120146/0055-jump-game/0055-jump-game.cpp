class Solution {
public:
    bool canJump(vector<int>& nums) {
       int rcbl =0;
       int n  = nums.size();
       for(int i = 0 ; i < n ; i++){
           if(i>rcbl) return false;
           if((i+nums[i])>rcbl) rcbl = i+nums[i];
        }
        return true;
  
        }
};