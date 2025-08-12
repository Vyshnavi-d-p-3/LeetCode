#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* links[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
        isEnd = false;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        isEnd = true;
    }

    bool isEndOfWord() {
        return isEnd;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            char currentChar = word[i];
            if (!node->containsKey(currentChar)) {
                node->put(currentChar, new TrieNode());
            }
            node = node->get(currentChar);
        }
        node->setEnd();
    }

    TrieNode* searchPrefix(const string& word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            char curLetter = word[i];
            if (node->containsKey(curLetter)) {
                node = node->get(curLetter);
            } else {
                return nullptr;
            }
        }
        return node;
    }

    bool search(string word) {
        TrieNode* node = searchPrefix(word);
        return node != nullptr && node->isEndOfWord();
    }

    bool startsWith(string prefix) {
        TrieNode* node = searchPrefix(prefix);
        return node != nullptr;
    }

    ~Trie() {
        // Optional: free all nodes recursively to avoid memory leaks
        clear(root);
    }

private:
    void clear(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < 26; i++) {
            clear(node->links[i]);
        }
        delete node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
