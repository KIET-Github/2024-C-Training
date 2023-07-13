class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long sum=0;
        long long maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
              sum += nums[i];

        if (sum > maxi) {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    
        }
        return maxi;
    }
};
