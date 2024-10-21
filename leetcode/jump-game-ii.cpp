// https://leetcode.com/problems/jump-game-ii/
class Solution {
public:
    int jump(vector<int>& nums) {
        int mx = 0;
        int curr = 0;
        int ans = 0;
        for(int i=0; i<nums.size() - 1; i++){
            mx = max(mx, nums[i] + i);
            if(curr == i){
                ans++;
                curr=mx;
            }
        }
        return ans;
    }
};