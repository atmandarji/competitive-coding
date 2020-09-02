// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        set<pair<int,int> > s;
        int mn=nums[0], mx=nums[0];
        s.insert(make_pair(nums[0],0));
        int li=0,i;
        int ans=1;
        for(i=1;i<nums.size();i++){
            mx=max(mx,nums[i]);
            mn=min(mn,nums[i]);
            s.insert(make_pair(nums[i],i));
            while(mx-mn>limit && !s.empty()){
                s.erase(s.find(make_pair(nums[li],li)));
                li++;
                mn=s.begin()->first;
                mx=s.rbegin()->first;
            }
            ans=max(ans,(int)s.size());
        }
        return ans;
    }
};
