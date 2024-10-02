//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool dfs(int node,vector<int> adj[],int vis[],int pathVis[])
    {
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node])
        {
            if(vis[it]==0)
            {
                if(dfs(it,adj,vis,pathVis)==true) return true;
            }
            else if(pathVis[it]==1)
            return true;
        }
        
        pathVis[node]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        int vis[v]={0};
        int pathVis[v]={0};
        for(int i=0;i<v;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(i,adj,vis,pathVis)==true) return true;
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends