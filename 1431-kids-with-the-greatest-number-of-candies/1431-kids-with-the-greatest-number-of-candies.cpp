class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& v, int e) {
        vector<bool>ans;
        auto maxElementIter = max_element(v.begin(), v.end());
        int mx = *maxElementIter;
        for(int i=0;i<v.size();i++){
            if(v[i]+e >= mx) ans.emplace_back(true);
            else ans.emplace_back(false);
        }
        return ans;
    }
};