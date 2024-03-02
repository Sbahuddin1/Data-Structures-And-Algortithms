#include <iostream>
#include <vector>
#include <algorithm>

// Define a class for tree nodes
class Node {
public:
    int key; // Key value of the node
    Node* parent; // Pointer to the parent node
    std::vector<Node*> children; // Vector to store pointers to child nodes

    Node() {
        this->parent = nullptr; // Initialize parent pointer to nullptr
    }

    // Method to set the parent of the node
    void setParent(Node* theParent) {
        parent = theParent;
        parent->children.push_back(this); // Add this node as a child of the parent
    }
};

// Function to compute the height of the tree
int computeHeight(Node* node) {
    if (node->children.empty()) // If the node has no children, return 1
        return 1;

    int maxHeight = 0;
    // Recursively calculate the height of each child node and find the maximum height
    for (auto child : node->children)
        maxHeight = std::max(maxHeight, computeHeight(child));

    return maxHeight + 1; // Return the maximum height of the children plus 1 for the current node
}

int main() {
    int n; // Number of nodes
    std::cin >> n; // Input the number of nodes

    std::vector<Node> nodes(n); // Create a vector of nodes

    int rootIndex = -1; // Index of the root node
    for (int i = 0; i < n; ++i) {
        int parentIndex;
        std::cin >> parentIndex; // Input the index of the parent node

        // Set the parent of the current node
        if (parentIndex >= 0)
            nodes[i].setParent(&nodes[parentIndex]); // Set the parent if the parent index is valid
        else
            rootIndex = i; // If parent index is negative, it indicates the root node
        nodes[i].key = i; // Assign a key value to the node
    }

    // Compute the height of the tree starting from the root node
    int maxHeight = computeHeight(&nodes[rootIndex]);

    // Output the height of the tree
    std::cout << maxHeight << std::endl;
    return 0;
}
