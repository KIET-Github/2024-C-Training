class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i  = 0;
        int j   =  0 ;
        int ans = 0 ;
        
        int kt = k;
        while(j<answerKey.size()){
            if(answerKey[j]=='T'  ){
                ans = max(ans , j-i+1);
                j++;
            }else{
                if(kt>0){
                   ans = max(ans , j-i+1);
                   j++;
                   kt--;
                }else{
                     while(kt==0 &&i<=j){
                         if(answerKey[i]=='F'){
                             kt++;
                         }i++;
                     }
                      ans = max(ans,j-i+1);
                }
            }
        }

        // check for f
           kt = k;
           i = 0 ;
           j = 0;
         while(j<answerKey.size()){
            if(answerKey[j]=='F' ){
                ans = max(ans , j-i+1);
                j++;
            }else{
                if(kt>0){
                   ans = max(ans , j-i+1);
                   j++;
                   kt--;
                }else{
                     while(kt==0 &&i<=j){
                         if(answerKey[i]=='T'){
                             kt++;
                         }i++;
                     }
                      ans = max(ans,j-i+1);
                }
            }
        }
 return ans;
    }
};