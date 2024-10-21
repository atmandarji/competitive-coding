//https://leetcode.com/problems/expressive-words/submissions/
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        vector<pair<char,int> > pat = makePattern(S);
        int ans=0;
        for(int i=0;i<words.size();i++){
            vector<pair<char,int> > q_pat = makePattern(words[i]);
            if(isStretchy(pat, q_pat)) ans++;
        }
        return ans;
    }
    
    vector<pair<char,int> > makePattern(string str){
        vector<pair<char,int> > pat;
        char curr=str[0];
        int freq=1;
        for(int i=1;i<str.size();i++){
            if(str[i]==curr)
                freq++;
            else{
                pat.push_back(make_pair(curr, freq));
                freq=1;
                curr=str[i];
            }
        }
        pat.push_back(make_pair(curr, freq));
        return pat;
    }
    
    bool isStretchy(vector<pair<char,int> > pat, vector<pair<char,int> > q_pat){
        if(pat.size()!=q_pat.size()) return false;
        
        for(int i=0;i<pat.size();i++){
            if(pat[i].first != q_pat[i].first) return false;
            if(pat[i].second < q_pat[i].second) return false;
            if(pat[i].second<3 && pat[i].second!=q_pat[i].second) return false;
        }
        return true;
    }
};