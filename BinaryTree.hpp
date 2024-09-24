#include "BinaryTreeNode.cpp"
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class BinaryTree {
public:
    BinaryTree(): root(nullptr), constructionState(false), lCount(0), rCount(0) {}
    BinaryTree(string, int);
    BinaryTree(const BinaryTree& t): constructionState(false), lCount(0), rCount(0) {
        root = BinaryTreeNode::Copy(t.root);
    }
    ~BinaryTree() {
        BinaryTreeNode::deleteTree(root);
    }
    
    void NameParenthesisTraversal() {
        NameParenthesis(root);
        cout << endl;
    }
    void PreorderTraversal() {
        Preorder(root);
        cout << endl;
    }
    void InorderTraversal() {
        Inorder(root);
        cout << endl;
    }
    void PostorderTraversal() {
        Postorder(root);
        cout << endl;
    }
    void LeftRightTraversal() {
        LeftRight(root);
        cout << endl;
    }

    int Height() {
        return TreeHeight(root);
    }
    int CountNodes() {
        return TreeCountNodes(root);
    }
    int CountNonLeafNodes() {
        return TreeCountNonLeafNodes(root);
    }
    int CountLeafNodes() {
        return TreeCountLeafNodes(root);
    }
    int CountDeg1Nodes() {
        return TreeCountDeg1Nodes(root);
    }
    int CountDeg2Nodes() {
        return TreeCountDeg2Nodes(root);
    }
    friend bool operator==(const BinaryTree& t1, const BinaryTree& t2) {
        return BinaryTreeNode::Equal(t1.root, t2.root);
    }
    friend bool operator!=(const BinaryTree& t1, const BinaryTree& t2) {
        return !BinaryTreeNode::Equal(t1.root, t2.root);
    }
    BinaryTree& operator=(const BinaryTree& t);


private:
    BinaryTreeNode* root;
    bool constructionState;
    int lCount, rCount;
    
    void Preorder(BinaryTreeNode*);
    void Inorder(BinaryTreeNode*);
    void Postorder(BinaryTreeNode*);
    void LeftRight(BinaryTreeNode*);
    void NameParenthesis(BinaryTreeNode*);

    BinaryTreeNode* NameParenthesisConstruction(stringstream&);
    BinaryTreeNode* InorderPreorderConstruction(string, string, int&);
    BinaryTreeNode* InorderPostorderConstruction(string, string, int&);
    BinaryTreeNode* InorderLevelorderConstruction(string, string, int&);
    BinaryTreeNode* LeftRightConstruction(string, int&);

    int TreeHeight(BinaryTreeNode*);
    int TreeCountNodes(BinaryTreeNode*);
    int TreeCountNonLeafNodes(BinaryTreeNode*);
    int TreeCountLeafNodes(BinaryTreeNode*);
    int TreeCountDeg1Nodes(BinaryTreeNode*);
    int TreeCountDeg2Nodes(BinaryTreeNode*);
};