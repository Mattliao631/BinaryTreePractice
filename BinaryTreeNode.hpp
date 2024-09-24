#include <string>

struct BinaryTreeNode {
    std::string data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(): data(""), left(nullptr), right(nullptr) {}
    BinaryTreeNode(std::string data): data(data), left(nullptr), right(nullptr) {}
    BinaryTreeNode(std::string data, BinaryTreeNode* left, BinaryTreeNode* right): data(data), left(left), right(right) {}
    
    BinaryTreeNode& operator=(const BinaryTreeNode& n);

    static BinaryTreeNode* Copy(const BinaryTreeNode*);
    static void deleteTree(BinaryTreeNode*);
    static bool Equal(BinaryTreeNode*, BinaryTreeNode*);
};