class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        int origColor = image[sr][sc];
        
        if(newColor == origColor) return image;

        dfs(image, sr, sc, origColor, newColor);
        return image;
    }
private:
    void dfs(vector<vector<int>>& image, int row, int col, int origColor, int newColor){

        if(row < 0 || col < 0 || row == image.size() || col == image[0].size() || image[row][col] != origColor) return;

        image[row][col] = newColor;

        dfs(image, row - 1, col , origColor, newColor);
        dfs(image, row + 1, col , origColor, newColor);
        dfs(image, row, col + 1 , origColor, newColor);
        dfs(image, row, col - 1 , origColor, newColor);
        
    }
};