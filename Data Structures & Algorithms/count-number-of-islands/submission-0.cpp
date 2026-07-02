class Solution {
public:

    void dfs(int r,int c,vector<vector<char>>& grid, vector<vector<bool>>& visited){
        visited[r][c]=1;
        int n=grid.size();
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        int row= r ,col=c ;
        for(int k=0;k<4;k++){
           row= r ,col=c ;
           int newrow=row+dr[k];
           int newcol=col+dc[k];
           if(newrow>=0 && newcol>=0 && newrow<n && newcol<grid[0].size())
{           if(grid[newrow][newcol]=='1' && !visited[newrow][newcol]){
            dfs(newrow,newcol,grid,visited);
           }}
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid[0].size();
        int r=grid.size();
        vector<vector<bool>> visited(r, vector<bool>(n, false));
        int islands=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                islands++;
                dfs(i,j,grid,visited);
            }
            }
        }
        return islands;
    }
};
