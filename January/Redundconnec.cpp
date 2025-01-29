class Solution {
public:
    vector<int> parent, rank;

    // Find function with path compression
    int find(int x) {
        if (parent[x] == x) return x; // If x is the root, return x
        return parent[x] = find(parent[x]); // Path compression
    }

    // Union function with union by rank
    bool unionSets(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) return false; // Cycle detected

        // Union by rank
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        // Initialize each node as its own parent (self-loop)
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        // Process each edge
        for (auto& edge : edges) {
            if (!unionSets(edge[0], edge[1])) {
                return edge; // This edge forms a cycle and is redundant
            }
        }

        return {}; // Should never reach here for a valid input
    }
};