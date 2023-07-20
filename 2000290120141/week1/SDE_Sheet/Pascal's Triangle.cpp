class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        ans.push_back({1});
        if(n==1)return ans;
        ans.push_back({1,1});
        if(n==2)return ans;
        for(int i=2;i<n;i++){
            vector<int>v(i+1,1);
            for(int j=1;j<i;j++){
                v[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(v);
        }
        return ans;
    }
};
