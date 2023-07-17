class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b=INT_MAX;
        int p=0;
        int s=0;
        for(int i=0;i<prices.size();i++)
        {
            b=min(b,prices[i]);
            s=prices[i]-b;
            p=max(p,s);
        }
        return p;
    }
};
