//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfs(int i,vector<int> adj[],vector<int> &vis,stack<int> &st)
    {
        vis[i]=1;
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis,st);
            }
        }
        st.push(i);
    }
    void revDFS(int i,vector<int> transpose[],vector<int> &vis)
    {
        vis[i]=1;
        for(auto it:transpose[i])
        {
            if(!vis[it])
            {
                revDFS(it,transpose,vis);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<vector<int>>& adjM)
    {
        //code here
        vector<int> adj[v];
        for(int i=0;i<v;i++)
        {
            for(auto it:adjM[i])
            {
                adj[i].push_back(it);
            }
        }
        vector<int> vis(v,0);
        stack<int> st;
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,st);
            }
        }
        vector<int> transpose[v];
        for(int i=0;i<v;i++)
        {
            vis[i]=0;
            for(auto it:adj[i])
            {
                transpose[it].push_back(i);
            }
        }
        int c=0;
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            if(!vis[node])
            {
                c++;
                revDFS(node,transpose,vis);
            }
        }
        return c;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends