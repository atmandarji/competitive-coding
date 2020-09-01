// https://leetcode.com/problems/hand-of-straights/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int w) {
        if(hand.size()%w) return false;
        sort(hand.begin(), hand.end());
        int i,j;
        vector<pair<int,int> > vp;
        int curr=hand[0];
        int freq=0;
        for(i=0;i<hand.size();i++){
            if(hand[i]==curr) freq++;
            else{
                vp.push_back(make_pair(curr,freq));
                freq=1;
                curr=hand[i];
            }
        }
        vp.push_back(make_pair(curr,freq));
        for(i=0;i<vp.size();i++){
            int cf=vp[i].second;
            vp[i].second=0;
            if(cf<1) continue;
            if(i+w>vp.size()) return false;
            int prev=vp[i].first;
            for(j=i+1;j<i+w;j++){
                if(vp[j].first-prev!=1) return false;
                prev=vp[j].first;
                if(vp[j].second<cf) return false;
                vp[j].second-=cf;
            }
        }
        return true;
    }
};
