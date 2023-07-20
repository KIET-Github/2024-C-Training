/* Leetcode link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        
        int maxi=0,mini=INT_MAX;
        int n=prices.size();

        for(int i=0;i<n;i++){

            mini=min(mini,prices[i]);
            
            int prof=prices[i]-mini;
            maxi=max(maxi,prof);
            

        }

return maxi;

    }
};
