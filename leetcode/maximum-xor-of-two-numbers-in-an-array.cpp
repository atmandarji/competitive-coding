// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

struct TrieNode{
    TrieNode *nextOne;
    TrieNode *nextZero;
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode *root = new TrieNode();
        root->nextOne = NULL;
        root->nextZero = NULL;
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++){
            TrieNode *temp = root;
            for(int shift=31; shift>=0; shift--){
                int iBit = (nums[i] & (1<<shift)) >> shift;
                if(iBit==0){
                    if(temp->nextZero)
                        temp = temp->nextZero;
                    else{
                        temp->nextZero = new TrieNode();
                        temp->nextZero->nextZero = NULL;
                        temp->nextZero->nextOne = NULL;
                        temp = temp->nextZero;
                    }
                }
                else{
                    if(temp->nextOne)
                        temp = temp->nextOne;
                    else{
                        temp->nextOne = new TrieNode();
                        temp->nextOne->nextZero = NULL;
                        temp->nextOne->nextOne = NULL;
                        temp = temp->nextOne;
                    }
                }
            }
        }
        
        for(int i=0; i<nums.size(); i++){
            TrieNode *temp = root;
            int toXorWith = 0;
            for(int shift=31; shift>=0; shift--){
                int iBit = (nums[i] & (1<<shift)) >> shift;
                if(iBit==0){
                    if(temp->nextOne){
                        temp = temp->nextOne;
                        toXorWith = toXorWith*2 + 1;
                    }
                    else {
                        temp = temp->nextZero;
                        toXorWith = toXorWith*2;
                    }
                }
                else {
                    if(temp->nextZero){
                        temp = temp->nextZero;
                        toXorWith = toXorWith*2;
                    }
                    else {
                        temp = temp->nextOne;
                        toXorWith = toXorWith*2 + 1;
                    }
                }
            }
            ans = max(ans, nums[i]^toXorWith);
        }
        return ans;
    }
};
