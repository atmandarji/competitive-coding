// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans=0;
        int n = heights.size();
        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int t = st.top();
                st.pop();
                ans = max(ans, heights[t] * (st.empty() ? i : i - 1 - st.top()));
            }
            st.push(i);
        }
        while(!st.empty()){
            int t = st.top();
            st.pop();
            ans = max(ans, heights[t] * (st.empty() ? n : n - 1 - st.top()));
        }
        return ans;
    }
};
