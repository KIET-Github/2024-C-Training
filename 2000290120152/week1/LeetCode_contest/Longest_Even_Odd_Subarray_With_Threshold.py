class Solution:
    def longestAlternatingSubarray(self, nums: List[int], threshold: int) -> int:
        n = len(nums)
        starts = []
        for i in range(n):
            if nums[i]%2==0 and nums[i]<=threshold:
                starts.append(i)
        max_len = 0
        cur_len = 0
        while(len(starts)):
            st = starts.pop(0)
            cur_len = 1
            # ed = n-1 #end
            for i in range(st+1,n):
                if nums[i]%2 != nums[i-1]%2 and nums[i]<=threshold:
                    cur_len += 1
                    continue
                else:
                    break
            # ln = ed-st+1
            max_len = max(max_len, cur_len)
        return max_len
