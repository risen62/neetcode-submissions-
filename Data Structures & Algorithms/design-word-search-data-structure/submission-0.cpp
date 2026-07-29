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
class WordDictionary {
   private:
    TrieNode* root;

   public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
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

    bool dfs(TrieNode* node, string& word, int i) {
        if (i == word.length()) {
            return node->isend;
        }
        int index;
        if (word[i] == '.') {
            for (int j = 0; j < 26; j++) {
                if (node->childern[j] != nullptr) {
                    if (dfs(node->childern[j], word, i + 1) == true) {
                        return true;
                    }
                }
            }
            return false;
        }
        if (word[i] != '.') {
            index = word[i] - 'a';
            if (node->childern[index] != nullptr) {
                return dfs(node->childern[index], word, i + 1);
            }
            return false;
        }
        return false;
    }
    bool search(string word) { 
        return dfs(root, word, 0); 
    }
};
