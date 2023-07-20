class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int>changes(2,0);
        for(auto i : bills){
       if(i==5){
          changes[0]++;
       }else if(i ==10){
            changes[1]++;
            changes[0]--;
           if(changes[0]<0) return false;
           
       }else{
           
             if(changes[1]>0){
                  changes[0]--;
            changes[1]--;

             }else{
                 changes[0] -=3;
                  
             }
           
           if(changes[0]<0 ||changes[1]<0) return false;
           
       }
        }
        return true;
        
    }
};