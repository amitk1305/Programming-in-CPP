/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int,int> imp;

    int solve(int id)
    {
        queue<int> q;
        int ans = 0;
        q.push(id);
        while(!q.empty())
        {

            int empid = q.front();
            ans+=imp[empid];
            q.pop();

            for(auto x : adj[empid])
            q.push(x);
        }
        return ans;
    }  
    int getImportance(vector<Employee*> emp, int id) { 

        for(int i = 0;i<emp.size();i++)
        {
            int empid = emp[i]->id;
            int import = emp[i]->importance;
            vector<int> sub = emp[i]->subordinates;

            imp[empid] = import;
            for(int j = 0;j<sub.size();j++)
            adj[empid].push_back(sub[j]);
        }
        return solve(id);
    }
};