class Solution {
public:
    
    int dfs(int r, int c,vector<vector<int>>& grid, vector<vector<bool>>& visited){
        visited[r][c]=1;
        int col_=grid[0].size();
        int row_=grid.size();
        int row=r,col=c;
        int dr[]={-1,1,0,0};
        int dc[] = {0,0,-1,1};
        int cells=1;
        for(int k=0;k<4;k++){
            int newrow=r+dr[k];
            int newcol=c+dc[k];
            if(newrow>=0 && newrow<row_ && newcol>=0 && newcol<col_){
                if(grid[newrow][newcol]==1 && !visited[newrow][newcol]){
                    cells+=dfs(newrow,newcol,grid,visited);
                }
            }
        }
     return cells;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int col=grid[0].size();
        int row=grid.size();
        vector<vector<bool>> visited(row,vector<bool>(col,0));
        int area=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1 && !visited[i][j]){ 
                    area=max(area,dfs(i,j,grid,visited));
                }
            }
        }
        return area;
    }
};
