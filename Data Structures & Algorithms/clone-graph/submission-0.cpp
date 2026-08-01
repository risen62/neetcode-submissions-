class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        
        unordered_map<Node*, Node*> visited;
        return dfs(node, visited);
    }
    
    Node* dfs(Node* original, unordered_map<Node*, Node*>& visited) {
        // Create copy of current node
        Node* copy = new Node(original->val);
        visited[original] = copy;
        
        // Go through each neighbor
        for (auto neighbor : original->neighbors) {
            if (visited.find(neighbor) == visited.end()) {
                // Not copied yet - recursively copy it
                Node* neighborCopy = dfs(neighbor, visited);
                copy->neighbors.push_back(neighborCopy);
            } else {
                // Already copied - use the existing copy
                copy->neighbors.push_back(visited[neighbor]);
            }
        }
        
        return copy;
    }
};