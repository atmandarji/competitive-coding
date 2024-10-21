// https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        mp[nums[0]]=1;
        int i;
        vector<int> ans;
        for(i=1;i<nums.size();i++){
            if(mp[target-nums[i]]>0){
                ans.push_back(mp[target-nums[i]]-1);
                ans.push_back(i);
                break;
            }
            mp[nums[i]]=i+1;
        }
        return ans;
    }
};
