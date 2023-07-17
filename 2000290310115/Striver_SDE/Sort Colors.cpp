class Solution {
public:
//optimal approach
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
      //better approach
        // int c0 =0, c1=0, c2=0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[i]==0)
        //         c0++;
        //     else if(nums[i]==1)
        //         c1++;
        //     else
        //         c2++;
        // }
        
        // int i=0;
        // while(c0>0)
        // {
        //     nums[i++]=0;
        //     c0--;
        // } 
        
        // while(c1>0)
        // {
        //     nums[i++]=1;
        //     c1--;
        // }
        
        // while(c2>0)
        // {
        //     nums[i++]=2;
        //     c2--;
        // }
    }
};
