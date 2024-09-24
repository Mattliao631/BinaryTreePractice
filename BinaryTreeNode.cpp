#include "BinaryTreeNode.hpp"

using namespace std;

BinaryTreeNode& BinaryTreeNode::operator=(const BinaryTreeNode& n) {
    if (this != &n) {
        deleteTree(this);
        return *Copy(&n);
    }
    return *this;
}
BinaryTreeNode* BinaryTreeNode::Copy(const BinaryTreeNode* n) {
    if (n == nullptr) {
        return nullptr;
    }
    return new BinaryTreeNode(n->data, Copy(n->left), Copy(n->right));
}

void BinaryTreeNode::deleteTree(BinaryTreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
}

bool BinaryTreeNode::Equal(BinaryTreeNode* root1, BinaryTreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }
    if (root1->data != root2->data) {
        return false;
    }
    if (Equal(root1->left, root2->left)) {
        return Equal(root1->right, root2->right);
    }
    return false; 
}