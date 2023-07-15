class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
         sort(g.begin(), g.end(), greater<int>());
 sort(s.begin(), s.end(), greater<int>());
        int ans = 0;
        int m = g.size() ;
        int n = s.size();
        int c = 0;
        for(int i = 0 ; i< m && ans < n ; i++){
  
           if(g[i]<=s[ans]){
           ans++;
         
           }
               
          
           
        }
        return ans;
        
    }
};