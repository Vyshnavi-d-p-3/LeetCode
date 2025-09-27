class Solution {
private:
    // Perform DFS and returns true if there is a path between src and target.
    bool isConnected(int src, int target, vector<bool>& visisted, vector<int> adjList[]) {
        visisted[src] = true;
        if(src == target) {
            return true;
        }

        int isFound = false;
        for(int adj : adjList[src]) {
            if(!visisted[adj]) {
                isFound = isFound || isConnected(adj, target, visisted, adjList);
            }
        }
        return isFound;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();

        vector<int> adjList[N];
        for (auto edge : edges) {
            vector<bool> visited(N, false);

            // If DFS returns true, we will return the edge.
            if (isConnected(edge[0] - 1, edge[1] - 1, visited, adjList)) {
                return edge;
            }

            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        return {};
    }
};