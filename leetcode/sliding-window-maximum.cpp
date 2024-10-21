// https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        for(int i=0; i<k; i++){
            while(!q.empty() && nums[q.front()]<nums[i])
                q.pop_front();
            q.push_front(i);
        }
        vector<int> ans;
        ans.push_back(nums[q.back()]);
        for(int i=k-1; i<nums.size()-1; i++){
            if(q.back() == i-(k-1))
                q.pop_back();
            while(!q.empty() && nums[q.front()]<nums[i+1])
                q.pop_front();
            q.push_front(i+1);
            ans.push_back(nums[q.back()]);
        }
        return ans;
    }
};
