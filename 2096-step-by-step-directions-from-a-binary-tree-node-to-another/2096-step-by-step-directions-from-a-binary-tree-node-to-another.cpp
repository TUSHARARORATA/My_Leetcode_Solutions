class Solution {
public:
        
	// Function to get LCA of given two nodes
    TreeNode* getLCA(TreeNode* root, int start, int dest) {
        if(!root) return NULL;
        
        if(root->val == start || root->val == dest) return root;
        
        TreeNode* left = getLCA(root->left, start, dest);
        TreeNode* right = getLCA(root->right, start, dest);
        
        if(left && right) return root;
        
        return left ? left : right;
    }
    
    bool traverse(TreeNode* root, string& path, int val) {
        if(!root) return false;
        
		// If node found, we have our path ready
		// So, no need to explore futher
		// Simply return true from here
        if(root->val == val) return true;
        
		// Try to find node in left direction
        path.push_back('L');
        if(traverse(root->left, path, val)) return true; // If found, then return 
        path.pop_back();  // If not found, then backtrack 
        
		// Try to find node in right direction
        path.push_back('R');
        if(traverse(root->right, path, val)) return true; // If found, then return 
        path.pop_back(); // If not found, then backtrack
        
		// If node is not found in any possible path, 
		// Then return false
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
		// Get LCA of start and destination node
        TreeNode* lca = getLCA(root, startValue, destValue);
        
        string lca_to_start = "", lca_to_dest = "";
        
		// Then find path from LCA to start 
		// as well as path from LCA to destination
        traverse(lca, lca_to_start, startValue);
        traverse(lca, lca_to_dest, destValue);
        
		// Since we need to move upward from start till LCA,
		// Thus, convert all characters in lca_to_start path to 'U'
        for(auto& c : lca_to_start) c = 'U';
       
	   // Concatenate both paths, to get shortest path from
	   // Start node -> Destination node.
        return lca_to_start + lca_to_dest;
    }
};