class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> graph;
        unordered_set<char> all_letters;
        unordered_map<char, int> indegree;
        for (auto word : words) {
            for (auto ch : word) {
                all_letters.insert(ch);
            }
        }
        for (auto c : all_letters) {
            indegree[c] = 0;
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            int minlen = min(word1.length(), word2.length());
            int indexpointer1 = 0;
            int indexpointer2 = 0;
            while (indexpointer1 < minlen && word1[indexpointer1] == word2[indexpointer2]) {
                indexpointer1++;
                indexpointer2++;
            }
            if (indexpointer1 == word1.length() || indexpointer2 == word2.length()) {
                if (word1.length() > word2.length()) {
                    return "";
                }
                continue;
            }
            if (word1[indexpointer1] != word2[indexpointer2]) {
                graph[word1[indexpointer1]].push_back(word2[indexpointer2]);
                indegree[word2[indexpointer2]]++;
            }
        }
        string result;
        queue<char> q;
        for (auto entry : indegree) {
            if (entry.second == 0) {
                q.push(entry.first);
            }
        }
        while (!q.empty()) {
            char current = q.front();
            result += current;
            q.pop();
            for (auto x : graph[current]) {
                indegree[x]--;
                if (indegree[x] == 0) {
                    q.push(x);
                }
            }
        }
        // Add this after the while loop:
        if (result.length() != all_letters.size()) {
            return "";
        }
        return result;
    }
};
