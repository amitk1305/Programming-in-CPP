class Solution {
public:
    bool checkValidString(string s) {
        int s1 = 0;
        int a = 0;
        for(auto &x : s)
        {
            if(x == '(') s1+=1;
            if(x == ')') s1-=1;
            else if ( x == '*') a++;
            if(s1<0)
            {
                if(a == 0) return 0;
                a--;
                s1++;
            }
        }
        if(s1 == 0) return 1;
        if( a >= s1)
        {

            s1 = 0;
        a = 0;
            for(int i = s.size() - 1 ; i >= 0 ; i--)
            {
                char x = s[i];
                if(x == '(') s1+=1;
                if(x == ')') s1-=1;
                else if ( x == '*') a++;
                if(s1>0)
                {
                    if(a <= 0) return 0;
                    a--;
                    s1--;
                }
            }
            return a >= (-1*s1);
        }

        //if(s1 >= 0 && a >= s1) return 1;
        return a >= (s1);
    }
};