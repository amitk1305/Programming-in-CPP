class Solution {
public:

    void dfs(int row,int col , vector<vector<int>> &grid , vector<vector<int>> &vis,int &area,int n,int m)
    {
        area=area+1;
        vis[row][col]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]==1 and vis[nrow][ncol]==0 )
            {
                dfs(nrow,ncol,grid,vis,area,n,m);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 and vis[i][j]==0)
                {
                    int area=0;
                    dfs(i,j,grid,vis,area,n,m);
                    max_area=max(area,max_area);
                }

            }
        }
        return max_area;
    }
};