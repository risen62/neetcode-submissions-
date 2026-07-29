class TrieNode {
public:
    TrieNode* childern[26];
    bool isend;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            childern[i] = nullptr;
        }
        isend = false;
    }
};

class PrefixTree {
private:
    TrieNode* root;  // ← ADD THIS!

public:
    PrefixTree() {
        root = new TrieNode();  // ← TrieNode constructor handles initialization
    }

    void insert(string word) {
        int index;
        TrieNode* node = root;
        for (auto x : word) {
            index = x - 'a';
            if (node->childern[index] == nullptr) {
                node->childern[index] = new TrieNode();
            }
            node = node->childern[index];
        }
        node->isend = true;
    }

    bool search(string word) {
        int index;
        TrieNode* node = root;
        for (auto x : word) {
            index = x - 'a';
            if (node->childern[index] == nullptr) {
                return false;
            }
            node = node->childern[index];
        }
        return node->isend;
    }

    bool startsWith(string prefix) {
        int index;
        TrieNode* node = root;
        for (auto x : prefix) {
            index = x - 'a';
            if (node->childern[index] == nullptr) {
                return false;
            }
            node = node->childern[index];
        }
        return true;
    }
};