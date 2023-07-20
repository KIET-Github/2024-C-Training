0/1 Knapsack:

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        int t[n+1][W+1];
       for(int i=0;i<n+1;i++){
           for(int j=0;j<W+1;j++){
               if(i==0 || j==0){
                   t[i][j]=0;
               }
           }
       }
       for(int i=1;i<n+1;i++){
           for(int j=1;j<W+1;j++){
               if(wt[i-1]<=j){
                   t[i][j]= max(t[i-1][j], val[i-1]+t[i-1][j-wt[i-1]]);
               }
               else{
                   t[i][j]=t[i-1][j];
               }
           }
       }
       return t[n][W];
    }
};


Partition Equal Subset Sum:

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }       
        if(sum%2!=0){
            return false;
        }
        else{
            sum=sum/2;
            bool t[n+1][sum+1];
            for(long long i=0;i<n+1;i++){
                for(long long j=0;j<sum+1;j++){
                    if(i==0){
                        t[i][j]=false;
                    }
                    if(j==0){
                        t[i][j]=true;
                    }
                }
            }
            for(long long i=1;i<n+1;i++){
                for(long long j=1;j<sum+1;j++){
                    if(nums[i-1]<=j){
                        t[i][j]=t[i-1][j] || t[i-1][j-nums[i-1]];
                    }
                    else{
                        t[i][j]=t[i-1][j];
                    }
                }
            }
            return t[n][sum];
        }
        
    }
};