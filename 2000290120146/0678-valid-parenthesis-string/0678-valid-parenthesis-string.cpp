class Solution {
public:
    bool checkValidString(string s) {
        stack<int>open , star;
        for(int i = 0 ; i< s.size() ; i++){
        if(s[i]=='('){
            open.push(i);
        }else if(s[i]=='*'){
            star.push(i);
        }else{
             if(!open.empty()){
                    open.pop();
             }else if( !star.empty()){
                 star.pop();
                 
             }else{
            return false;
             }
            
        }
        }
        if(!open.empty()){
       
            while(!open.empty()){
                  if(star.empty()) return false;
                int a = open.top();
                int b = star.top();
                open.pop();
                star.pop();
                if(a>b) return false;
      
        }
        }
        return true;
        
    }
};