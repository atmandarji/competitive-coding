// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int i=0,j=0,n=arr.size();
        vector<pair<int,int> > pairs;
        long long sum=arr[0];
        while(j<n){
            if(sum==target){
                pairs.push_back(make_pair(i,j));
                sum -= arr[i];
                i++;
                j++;
                if(j<n) sum += arr[j];
            }
            else if(sum<target){
                j++;
                if(j<n) sum += arr[j];
            }
            else{
                sum -= arr[i];
                i++;
            }
        }
        i=0;
        j=0;
        int ans=INT_MAX;
        priority_queue<int, vector<int>, greater<int>> q;
        while(i<pairs.size()){
            while(j<i && pairs[j].second < pairs[i].first){
                q.push(pairs[j].second - pairs[j].first + 1);
                j++;
            }
            if(!q.empty())
                ans = min(ans, q.top()+pairs[i].second-pairs[i].first+1);
            i++;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
