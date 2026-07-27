class Solution {
private:
    int rows;
    int columns;
    vector<vector<int>> directions  = {{1,0},{-1,0},{0,1},{0,-1}};
   
    
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int idx) {
        if(idx == word.length())return true;
        if(r<0 || r>= rows || c<0 ||  c>=columns || board[r][c] != word[idx]){
            return false;
        }
        char temp = board[r][c];
        board[r][c] = '#';
        for(auto const &dir : directions){
            if(dfs(board,word,r + dir[0],c + dir[1],idx + 1) == true){
                return true;
            }
        }
        board[r][c] = temp;
        return false;
        
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
         rows = board.size();
         columns = board[0].size();
        for(int r = 0;r<rows;r++){
            for(int c = 0;c<columns;c++){
                if(board[r][c] == word[0] && dfs(board,word,r,c,0) == true){
                    return true;

                }
            }
        }
        return false;
       
    }
};