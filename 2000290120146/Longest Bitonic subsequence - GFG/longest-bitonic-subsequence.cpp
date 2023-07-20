//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	     int n = nums.size();
	    vector<int> dp(n , 1), bdp(n , 1);
	   
	    for(int i = 1 ; i < n ; i++){
	        for(int  j =  0 ; j < i ; j++){
	            if(nums[j]<nums[i]&& dp[i]<1+dp[j]){
	                dp[i] = 1+dp[j];
	            }
	        }
	    }
	        for(int i = n-2 ; i >=0 ; i--){
	        for(int  j =  n-1 ; j > i ; j--){
	            if(nums[j]<nums[i]&& bdp[i]<1+bdp[j]){
	                bdp[i] = 1+bdp[j];
	            }
	        }
	    }
	    int ans = 0;
	    for(int i = 0 ; i < n ; i++){
	       int t =  dp[i]+bdp[i];
	       ans = max(ans , t);
	        
	    }
	    return ans-1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends