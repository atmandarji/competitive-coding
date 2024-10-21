// https://leetcode.com/problems/validate-stack-sequences/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0,j,n=pushed.size();
        for(j=0;j<n;j++){
            while((st.empty() || st.top()!=popped[j]) && i<n){
                st.push(pushed[i]);
                i++;
            }
            if(st.top() != popped[j]) return false;
            st.pop();
        }
        return true;
    }
};
