class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int visitednodes = 0;
        vector<bool> visited(n,false);
        if (edges.size() != n - 1) {
            return false;
        }
        vector<vector<int>> adjlist(n);
        for (auto edge : edges) {
            int a = edge[0];
            int b = edge[1];
            adjlist[b].push_back(a);
            adjlist[a].push_back(b);
        }
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
            int current = q.front();
            q.pop();
            visitednodes++;
            for(int x : adjlist[current]){
                if(visited[x] == false){
                    visited[x] = true;
                    q.push(x);
                }
            } 
        }
        if(visitednodes == n){
            return true;
        }else{
            return false;
        }
    }
};
