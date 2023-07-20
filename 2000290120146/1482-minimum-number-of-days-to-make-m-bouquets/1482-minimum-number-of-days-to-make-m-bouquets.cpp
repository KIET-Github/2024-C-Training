class Solution {
public:
   bool f(int ii , int jj  , vector<int>&bloomDay , int m , int k ){
       int mid = (ii+jj)/2;
       vector<int>temp(bloomDay.size() , 0);
       for(int i =  0 ; i < bloomDay.size() ; i++){
           if(bloomDay[i]<=mid){
               temp[i] = 1;
           }
       }
       int ans =0;
       int count =0 ;
       for(int i =  0   ; i< temp.size() ; i++){
           if(temp[i]==1){
             count++;
             if(count==k){ 
                 count = 0 ;
                 ans++;}
           }else{
               count  = 0;
           }
       }
       if(ans>=m) return true;
       return false;
   }
    int minDays(vector<int>& bloomDay, int m, int k) {

        if(1ll*m*k*1ll>bloomDay.size()*1ll) return -1;
     int ans = INT_MAX;
     int i = *min_element(bloomDay.begin() , bloomDay.end()) ;
     int j = *max_element(bloomDay.begin() , bloomDay.end());
     while(i<=j){
         int mid = (i+j)/2;
         if(f(i , j,bloomDay , m , k)){
             ans = min(ans , mid);
             j = mid-1;
         }else{
             i = mid+1;
         }

     }
     return ans ;

    }
};