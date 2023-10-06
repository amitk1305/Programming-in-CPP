class Solution {
public:
    
    vector<vector<int> > g;
    int n, m, c, mx, w, r, ans, itr;
    unordered_set<int> s;
    
    int dfs(int i, int j){
        if(i<0 || i>=n || j<0 || j>=m || g[i][j]!=1)
            return 0;
        int ans=0;
        if(i+1<n && g[i+1][j]==0){
            s.insert((i+1)*m+j);
            ans++;
        }
        if(i-1>=0 && g[i-1][j]==0){
            s.insert((i-1)*m+j);
            ans++;
        }
        if(j+1<m && g[i][j+1]==0){
            s.insert(i*m+(j+1));
            ans++;
        }
        if(j-1>=0 && g[i][j-1]==0){
            s.insert(i*m+(j-1));
            ans++;
        }
        g[i][j]=c;
        ans+=dfs(i+1, j);
        ans+=dfs(i-1, j);
        ans+=dfs(i, j+1);
        ans+=dfs(i, j-1);
        return ans; // total number of walls needed to block this connected component
    }
    
    int containVirus(vector<vector<int>>& grid) {
        g=grid, n=g.size(), m=g[0].size(), ans=0;
        while(true){
            c=2, mx=0;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(g[i][j]==1){
                        s.clear();
                        int walls=dfs(i, j);
                        if(mx<s.size()){
                            mx=s.size();
                            w=walls;
                            r=c;
                        }
                        c++;
                    }
                }
            }
            if(mx==0)
                break;
            ans+=w;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(g[i][j]==r)
                        g[i][j]=1e9;
                    else if(g[i][j]>1 && g[i][j]!=1e9){
                        g[i][j]=1;
                        if(i+1<n && !g[i+1][j]) g[i+1][j]=1;
                        if(i-1>=0 && !g[i-1][j]) g[i-1][j]=1;
                        if(j+1<m && !g[i][j+1]) g[i][j+1]=1;
                        if(j-1>=0 && !g[i][j-1]) g[i][j-1]=1;
                    }
                }
            }
        }
        return ans;
    }
};