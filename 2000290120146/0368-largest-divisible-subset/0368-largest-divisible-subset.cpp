class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin() , nums.end());
         int n = nums.size();
        vector<int> temp(nums.size() , 1)  ;
        vector<int>hash;
        for(int i= 0 ; i < nums.size() ; i++) hash.push_back(i);
        for(int i =1 ; i< n  ; i++){
            for(int j = 0 ; j<i ; j++){
                if(nums[i]%nums[j]==0 && 1+temp[j]>temp[i]){
                    temp[i] = 1+temp[j];
                    hash[i] = j;
                }
            }
        }
        int value = INT_MIN;
        int index=0;
        for(int i = 0 ; i < n ; i++){
            if(temp[i]>value)  {
                value = temp[i];
                index = i;}
        }
        vector<int> ans;
        ans.push_back(nums [index]);
        while(index!=hash[index]){
            
            index = hash[index];
            ans.push_back(nums [index]);

        }
        reverse(ans.begin() , ans.end());
        return ans ;

    }
};