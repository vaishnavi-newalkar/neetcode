class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // Check rows
        for(int i = 0; i < 9; i++){
            vector<int> visited(10, 0);
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                
                int num = board[i][j] - '0';
                
                if(visited[num]) return false;
                visited[num] = 1;
            }
        }

        // Check columns
        for(int j = 0; j < 9; j++){
            vector<int> visited(10, 0);
            for(int i = 0; i < 9; i++){
                if(board[i][j] == '.') continue;
                
                int num = board[i][j] - '0';
                
                if(visited[num]) return false;
                visited[num] = 1;
            }
        }

        // Check 3x3 boxes
        for(int boxRow = 0; boxRow < 3; boxRow++){
            for(int boxCol = 0; boxCol < 3; boxCol++){
                
                vector<int> visited(10, 0);

                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        
                        char val = board[boxRow*3 + i][boxCol*3 + j];
                        
                        if(val == '.') continue;
                        
                        int num = val - '0';
                        
                        if(visited[num]) return false;
                        visited[num] = 1;
                    }
                }
            }
        }

        return true;
    }
};