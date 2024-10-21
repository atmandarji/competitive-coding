// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        multiset<int> s;
        for(int i=0;i<nums.size();i++)
            s.insert(nums[i]);
        while(!s.empty()){
            int first=*s.begin();
            s.erase(s.begin());
            for(int j=first+1;j<first+k;j++){
                if(s.find(j)==s.end()) return false;
                s.erase(s.find(j));
            }
        }
        return true;
    }
};

int main(){
    int n,k;
    cin >>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >>v[i];
    cin >>k;
    Solution s;
    cout <<s.isPossibleDivide(v,k)<<endl;;
}
