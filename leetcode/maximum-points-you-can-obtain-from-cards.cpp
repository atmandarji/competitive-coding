// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i,j;
        long long sum=0;
        for(i=0;i<k;i++)
            sum += cardPoints[i];
        long long ans=sum;
        i=k-1;
        j=cardPoints.size()-1;
        while(i>=0){
            sum-=cardPoints[i];
            sum+=cardPoints[j];
            j--;
            i--;
            ans=max(ans,sum);
        }
        return ans;
    }
};
