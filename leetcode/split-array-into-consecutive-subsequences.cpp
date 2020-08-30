//https://leetcode.com/problems/split-array-into-consecutive-subsequences/
class Solution {
public:
    bool possible(vector<int> &nums) {
        if(nums.size()<3) return false;
        
        int i,j,o=0,t=0,m=0;
        map<int,int> freq;
        for(i=0;i<nums.size();i++)
            freq[nums[i]]++;
        for(i=nums[0];i<=nums.back();i++){
            if(freq[i]==0) continue;
            
            if(o+t<=freq[i]){
                int r=max(freq[i]-o-t-m, 0);
                m=t+min(freq[i]-o-t,m);
                t=o;
                o=r;
            }
            else
                return false;
        }
        if(o+t>0 || m<1) return false;
        return true;
    }

    bool isPossible(vector<int>& nums) {
        vector<vector<int> > cont;
        int i;
        vector<int> curr;
        curr.push_back(nums[0]);
        for(i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<2)
                curr.push_back(nums[i]);
            else{
                cont.push_back(curr);
                vector<int> temp;
                curr=temp;
                curr.push_back(nums[i]);
            }
        }
        cont.push_back(curr);
        bool ans=true;
        for(i=0;i<cont.size();i++)
            ans &= possible(cont[i]);
        return ans;
    }
};