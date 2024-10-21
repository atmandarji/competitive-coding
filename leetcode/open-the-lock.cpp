// https://leetcode.com/problems/open-the-lock/
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, int> level;
        level["0000"]=1;
        unordered_set<string> ds;
        int i;
        for(i=0;i<deadends.size();i++)
            ds.insert(deadends[i]);
        if(ds.find("0000")!=ds.end()) return -1;

        queue<string> q;
        q.push("0000");
        while(!q.empty()){
            string f = q.front();
            if(f==target) return level[f]-1;

            q.pop();
            for(i=0;i<4;i++){
                string temp=f;
                temp[i]=(temp[i]+1-'0')%10 + '0';
                if(!level[temp] && ds.find(temp)==ds.end()){
                    level[temp] = level[f]+1;
                    q.push(temp);
                }
                temp=f;
                temp[i]=(temp[i]-1-'0'+10)%10 + '0';
                if(!level[temp] && ds.find(temp)==ds.end()){
                    level[temp] = level[f]+1;
                    q.push(temp);
                }
            }
        }
        return -1;
    }
};
