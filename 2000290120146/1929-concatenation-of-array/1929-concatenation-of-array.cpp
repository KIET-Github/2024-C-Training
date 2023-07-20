class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i <n  ; i++){
            int ii = nums[i];
            nums.push_back(ii);
        }
        return nums;
        
    }
};