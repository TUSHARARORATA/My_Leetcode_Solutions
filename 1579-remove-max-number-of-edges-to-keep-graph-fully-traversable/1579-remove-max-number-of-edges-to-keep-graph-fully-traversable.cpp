class UnionFind {
private:
    vector<int> parent;
    int groups;

public:
    // Initialize the UnionFind data structure with n groups
    UnionFind(int n) : parent(n + 1), groups(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    // Union two elements and return 1 if they were not already in the same group, 0 otherwise
    int union_(int u, int v) {
        const int uParent = find_(u);
        const int vParent = find_(v);
        if (uParent == vParent)
            return 0;
        parent[uParent] = vParent;
        --groups;
        return 1;
    }

    // Find the parent of an element and perform path compression
    int find_(int v) {
        if (parent[v] != v)
            parent[v] = find_(parent[v]);
        return parent[v];
    }

    // Check if all elements are in the same group
    bool is_united() {
        return groups == 1;
    }
};
class Solution {
private:
    // constants for the edge types indices
    static constexpr int 
        TYPE = 0, U = 1, V =2,
        ALICE = 1, BOB = 2, BOTH = 3;

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // Move all edges of type BOTH to the end of the array
        for (int i = 0, j = edges.size() - 1; i < j; ) {
            if (edges[i][TYPE] == BOTH) {
                ++i;
                continue;
            }
            swap(edges[i], edges[j]);
            --j;
        }

        // Create two UnionFind data structures, one for Alice and one for Bob
        UnionFind alice_uf(n), bob_uf(n);
        int added = 0;

        // Iterate over the edges and add them to the appropriate UnionFind data structure
        for (const auto& edge : edges) {
            const int type = edge[TYPE];
            const int u = edge[U];
            const int v = edge[V];

            // Add the edge to both UnionFind data structures if it is of type BOTH
            added += (type == BOTH) ? 
                alice_uf.union_(u, v) | bob_uf.union_(u, v) :
                (type == ALICE) ? alice_uf.union_(u, v) : bob_uf.union_(u, v);

            // If both UnionFind data structures are united, return the number of edges that were not added
            if (alice_uf.is_united() && bob_uf.is_united())
                return edges.size() - added;
        }

        // If both UnionFind data structures are united, return the number of edges that were not added
        if (alice_uf.is_united() && bob_uf.is_united())
            return edges.size() - added;

        // If both UnionFind data structures are not united, it is impossible to remove enough edges to make them united
        return -1;
    }
};

