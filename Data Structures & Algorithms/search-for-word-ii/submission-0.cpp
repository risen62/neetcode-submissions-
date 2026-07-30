class Solution {
public:
    struct TrieNode {
        TrieNode* child[26] = {};
        string word = ""; // stores the complete word at the end node
    };

    TrieNode* root = new TrieNode();

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx]) node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->word = word; // mark end of word
    }

    int rows, cols;
    vector<vector<char>> grid;
    set<string> result;

    void dfs(int r, int c, TrieNode* node) {
        char ch = grid[r][c];
        int idx = ch - 'a';
        if (idx < 0 || !node->child[idx]) return;

        TrieNode* next = node->child[idx];
        if (!next->word.empty()) {
            result.insert(next->word);
            // don't return here — could still extend to a longer word
        }

        grid[r][c] = '#'; // mark visited

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] != '#') {
                dfs(nr, nc, next);
            }
        }

        grid[r][c] = ch; // backtrack
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        grid = board;
        rows = board.size();
        cols = board[0].size();

        for (const string& w : words) insert(w);

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(r, c, root);
            }
        }

        return vector<string>(result.begin(), result.end());
    }
};