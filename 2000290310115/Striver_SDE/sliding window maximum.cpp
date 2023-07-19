class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int>q;
       vector<int>res;
       for(int i=0;i<nums.size();i++)
       {
           if(!q.empty()&&q.front()==i-k)
           q.pop_front();
           while(!q.empty()&&nums[q.back()]<nums[i])
           q.pop_back();
           q.push_back(i);
           if(i>=k-1)
           res.push_back(nums[q.front()]);
       }
       return res;
        // vector<int>res;
        // multiset<int,greater<int>>ms;
        // int i=0,j=0,n=nums.size();
        // while(j<n)
        // {
        //     ms.insert(nums[j]);
        //     if(j-i+1==k)
        //     {
        //         res.push_back(*ms.begin());
        //         ms.erase(ms.find(nums[i]));
        //         i++;
        //         j++;
        //     }
        //     else
        //     j++;
        // }
        // return res;
        
    }
};
