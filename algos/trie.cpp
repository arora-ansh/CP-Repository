#include<bits/stdc++.h>
using namespace std;

/*
This is used in the case of fast retrieval of only 26 capital/small alphabets, but might lead to storage waste

#define N 26

struct TrieNode{
    vector<TrieNode*> children(N); 
}


struct TrieNode{
    unordered_map<char, TrieNode*> children;
}

*/

class Trie {
private:
    struct TrieNode{
        struct TrieNode *children[26];
        bool isEnd = false;
    };
public:
    TrieNode* trieRoot;
    Trie() {
        trieRoot = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = trieRoot;
        for(char c : word){
            if(!cur->children[c-'a']) cur->children[c-'a'] = new TrieNode();
            cur = cur->children[c-'a'];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = trieRoot;
        for(char c : word){
            if(!cur->children[c-'a']) return false;
            cur = cur->children[c-'a'];
        }
        if(cur->isEnd) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = trieRoot;
        for(char c: prefix){
            if(!cur->children[c-'a']) return false;
            cur = cur->children[c-'a'];
        }
        return true;
    }
};
