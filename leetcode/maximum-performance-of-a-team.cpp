// https://leetcode.com/problems/maximum-performance-of-a-team/
// Asked in BookMyShow
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int> > vp;
        int i;
        for(i=0;i<speed.size();i++)
            vp.push_back(make_pair(efficiency[i], speed[i]));
        sort(vp.begin(),vp.end());
        reverse(vp.begin(),vp.end());
        priority_queue<int, vector<int>, greater<int> > q;
        long long sum=0;
        long long ans=0;
        for(i=0;i<speed.size();i++){
            sum+=vp[i].second;
            q.push(vp[i].second);
            long long eff=vp[i].first;
            if(q.size()>k){
                sum -= q.top();
                q.pop();
            }
            ans=max(ans,eff*sum);
        }
        return ans%1000000007;
    }
};
