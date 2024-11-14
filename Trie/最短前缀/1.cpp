#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int count; // ��¼�����ýڵ�ĵ�������

    TrieNode() : count(0) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // ���뵥�ʵ��ֵ���
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

    // ��ȡ���ʵ����Ψһǰ׺
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
        return prefix; // ���ʱ���Ϊ���ǰ׺
    }
};

int main() {
    vector<string> words;
    string word;

    // �ӱ�׼�����ȡ�����б�
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


