#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int count; // 记录经过该节点的单词数量

    TrieNode() : count(0) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // 插入单词到字典树
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
            node->count++;
        }
    }

    // 获取单词的最短唯一前缀
    string getUniquePrefix(const string& word) {
        TrieNode* node = root;
        string prefix;
        for (char ch : word) {
            prefix += ch;
            node = node->children[ch];
            if (node->count == 1) {
                return prefix;
            }
        }
        return prefix; // 单词本身即为最短前缀
    }
};

int main() {
    vector<string> words;
    string word;

    // 从标准输入读取单词列表
    while (getline(cin, word) && !word.empty()) {
        words.push_back(word);
    }

    Trie trie;
    for (const string& w : words) {
        trie.insert(w);
    }

    for (const string& w : words) {
        string prefix = trie.getUniquePrefix(w);
        cout << w << " " << prefix << endl; 
    }

    return 0;
}


