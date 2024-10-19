#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    Node *child[26];
    int f;
    bool isWordEnd;
    Node(){
        for(int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
        isWordEnd = false;
        f = 0;
    }
};

class Trie {
    private: 
    Node *root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string str) {
        int len = str.length();
        Node *curr = root;
        for(int i = 0; i < len; i++) {
             int chIdx = str[i] - 'a';
           
            if(curr->child[chIdx] == nullptr) {
                curr->child[chIdx] = new Node();
            }
            //curr->f++;
            curr = curr->child[chIdx];
            curr->f++;
        }
        curr->isWordEnd = true;
    }
    bool search(string str) {
        Node *curr = root;
        int len = str.length();
        if(curr == nullptr) return 0;

        for(int i = 0; i < len; i++) {
            int chIdx = str[i] - 'a';
            if(curr->child[chIdx] == nullptr) return 0; 
            curr = curr->child[chIdx];
        }
        return curr->isWordEnd;
    }


    int startWith(string str) {
         Node *curr = root;
        int len = str.length();
        if(root == nullptr) return 0;
        for(int i = 0; i < len; i++) {
            int chIdx = str[i] - 'a';
            if(curr->child[chIdx] == nullptr) return 0; 
            curr = curr->child[chIdx];
        }
        return curr->f;
    }
};

int main() {

    Trie trie;

    trie.insert("yeasin");
    trie.insert("yeasin");
    trie.insert("yeasintest");

    cout<<trie.startWith("yeasin")<<endl;

    return 0;
}