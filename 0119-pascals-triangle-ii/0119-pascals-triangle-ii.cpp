class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Initialize the row with 1s
        vector<int> row(rowIndex + 1, 1);  
        // Calculate each element of the row based on the previous row
        for (int i = 0; i <= rowIndex; ++i) {
            for (int j = i - 1; j > 0; --j) {
                row[j] = row[j] + row[j - 1];
            }
        }
        return row;
    }
};