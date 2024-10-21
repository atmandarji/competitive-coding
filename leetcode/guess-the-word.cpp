// https://leetcode.com/problems/guess-the-word/
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int t=10,i;
        vector<string> scope=wordlist;
        while(t--){
            int n=scope.size();
            int p=rand()%n;
            int match=master.guess(scope[p]);
            if(match==6) return;
            
            vector<string> temp;
            for(i=0;i<scope.size();i++)
                if(calc(scope[p], scope[i])==match)
                    temp.push_back(scope[i]);
            scope=temp;
        }
        return;
    }
    int calc(string s1, string s2){
        int ans=0,i;
        for(i=0;i<6;i++){
            if(s1[i]==s2[i]) ans++;
        }
        return ans;
    }
};
