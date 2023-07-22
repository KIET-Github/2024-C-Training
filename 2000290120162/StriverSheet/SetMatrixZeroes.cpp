//Leetcode link: https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {

    int row=m.size(),col=m[0].size();
   
        int x=1,y=1;// to check natural zero of first row & col

        for(int i=0;i<row;i++){
            if(m[i][0]==0)
                x=0;
        }
        for(int j=0;j<col;j++){
            if(m[0][j]==0)
                y=0;
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(m[i][j]==0){
                    m[i][0]=0;
                    m[0][j]=0;
                }
            }
        }

        for(int i=1;i<row;i++){
            if(m[i][0]==0){
                for(int j=1; j<col;j++){
                    m[i][j]=0;
                }
            }
        }
         for(int j=1;j<col;j++){
            if(m[0][j]==0){
                for(int i=1; i<row;i++){
                    m[i][j]=0;
                }
            }
        }

        if(x==0){
            for(int i=0;i<row;i++){
                m[i][0]=0;
            }
        }
        
        if(y==0){
            for(int j=0;j<col;j++){
                m[0][j]=0;
            }
        }




    }
};
