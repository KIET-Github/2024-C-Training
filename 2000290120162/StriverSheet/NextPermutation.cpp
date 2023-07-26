//Leetcode link: https://leetcode.com/problems/next-permutation/description/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int n=nums.size();
        int infPoint=0;
       for(int i=n-1;i>0;i--){
           if(nums[i]>nums[i-1]){
               infPoint=i;
               break;
           }
       }

    if(infPoint==0){
        sort(nums.begin(),nums.end());
    }
    else{
        int toSwap=nums[infPoint-1];
        int mini=INT_MAX;
        for(int i=infPoint;i<n;i++){
            if(nums[i]>toSwap && nums[i]-toSwap<mini){
                swap(nums[infPoint-1],nums[i]);
            }
        }

        sort(nums.begin()+infPoint,nums.end());

    }
    
       
    }
};
