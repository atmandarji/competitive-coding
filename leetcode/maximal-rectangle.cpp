// https://leetcode.com/problems/maximal-rectangle/

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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        vector<int> heights(matrix[0].size(),0);
        int ans=0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0;j<matrix[i].size(); j++){
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j]=0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
};