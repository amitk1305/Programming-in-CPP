class Solution {
public:
    char findTheDifference(string s, string t) {
      int sumS = 0;
      int sumT = 0;
       for (auto i: s){
         sumS += i;
       }
       for (auto n: t){
         sumT += n;
       }
        return char(abs(sumS - sumT));
    }
};