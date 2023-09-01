class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int len1 = a.length();
        int len2 = b.length();
        if(a == b) return 1;
        // If both the strings are equal then return 1
        int count = 0;
        string str = a;
        while(a.length() <= 10000){
            //This condidtion is used to check whether the length of
            // a is less than 10^4 or not. The moment the length
            //exceeds 10^4 then return false becoz the max length of
            //a can be 10^4 refers Constraint
            count++;
            int foundPos = a.find(b);
            //The .find() function returns the position (index) of
            //the first occurrence of the substring b within the 
            //string a. If the substring is not found, it returns a
            //special value, usually -1
            if(foundPos != -1) return count;
            //if foundpos == 1 i.e the string b is a substr of a then
            //return count
            a += str;
        }
        return -1;

        
    }
};