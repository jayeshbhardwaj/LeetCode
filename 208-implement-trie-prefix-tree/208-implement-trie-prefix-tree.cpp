class Trie {
public:
    class Node{
      public:
      Node* nbs[26];
      bool isLeaf;
    };
    Node *root;
    
    Trie() {
       root = new Node(); 
    }

    
    void insert(string word) {
      Node *node = root;
      for(int i=0;i<word.length();i++){
        if(node->nbs[word[i]-'a']==NULL){
          Node *child = new Node();
          node->nbs[word[i]-'a'] =  child;
          node = child;
        }
        else 
          node = node->nbs[word[i]-'a'];
      }
      node->isLeaf=true;
      
    }
    
    bool search(string word) {
        Node *node = root;
        for(int i=0;i<word.length();i++){
          if(node->nbs[word[i]-'a']==NULL) return false;
          else node=node->nbs[word[i]-'a'];
        }
        return node->isLeaf;
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i=0;i<prefix.length();i++){
          if(node->nbs[prefix[i]-'a']==NULL) return false;
          else node=node->nbs[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */