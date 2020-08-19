// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3ff3
#include<bits/stdc++.h>
using namespace std;

struct trie_node{
  struct trie_node *children[26];
  bool is_end;
  long long prefix_freq;
};

trie_node* make_node(){
  trie_node *node = new trie_node;
  node->is_end=false;
  node->prefix_freq=1;
  for(int i=0;i<26;i++){
    node->children[i]=NULL;
  }
  return node;
}

void insert(trie_node *root, string str){
  int i=0;
  int char_num = (int)(str[i]-'A');
  while(root->children[char_num]){
    root = root->children[char_num];
    root->prefix_freq++;
    i++;
    if(i>=str.size()) break;
    char_num = (int)(str[i]-'A');
  }
  while(i<str.size()){
    char_num = (int)(str[i]-'A');
    root->children[char_num] = make_node();
    root = root->children[char_num];
    i++;
  }
  root->is_end = true;
}

void solve(){
  int n,k,i;
  cin >>n>>k;
  trie_node *root = make_node();
  root->prefix_freq=0;
  for(i=0;i<n;i++){
    string str;
    cin >>str;
    insert(root, str);
  }
  queue<trie_node*> q;
  q.push(root);
  long long ans=0;
  while(!q.empty()){
    trie_node *curr = q.front();
    q.pop();
    ans += curr->prefix_freq/k;
    for(i=0;i<26;i++)
      if(curr->children[i]) q.push(curr->children[i]);
  }
  cout <<ans;
}

int main(){
  int t;
  cin >>t;
  for(int i=1;i<=t;i++){
    cout <<"Case #"<<i<<": ";
    solve();
    cout <<endl;
  }
  return 0;
}
