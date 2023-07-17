class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
        if(st.size()==0)
        {
            st.push(s[i]);
        }
        else if(st.top()=='('&&s[i]==')'||st.top()=='{'&&s[i]=='}'||st.top()=='[' && s[i]==']')
        {
            st.pop();
        }
        else
        st.push(s[i]);
        }
        if(st.size()==0)
        return true;
        else
        return false;
    }
};
