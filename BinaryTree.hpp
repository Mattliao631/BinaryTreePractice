#include "BinaryTreeNode.cpp"
#include <sstream>
#include <string>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

#define VALID_TREE() {if (!constructionState) { cout << "Invalid Tree" << endl; return;}}
#define VALID_TREE_R(x) {if (!constructionState) { cout << "Invalid Tree" << endl;return (x);}}

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
    
    void NameParenthesisTraversal();
    void PreorderTraversal();
    void InorderTraversal();
    void PostorderTraversal();
    void LevelorderTraversal();
    void LeftRightTraversal();

    int Height();
    int CountNodes();
    int CountNonLeafNodes();
    int CountLeafNodes();
    int CountDeg1Nodes();
    int CountDeg2Nodes();

    friend bool operator==(const BinaryTree& t1, const BinaryTree& t2);
    friend bool operator!=(const BinaryTree& t1, const BinaryTree& t2);
    BinaryTree& operator=(const BinaryTree& t);


private:
    BinaryTreeNode* root;
    bool constructionState;
    int lCount, rCount;
    
    void Preorder(BinaryTreeNode*);
    void Inorder(BinaryTreeNode*);
    void Postorder(BinaryTreeNode*);
    void Levelorder(BinaryTreeNode*);
    void LeftRight(BinaryTreeNode*);
    void NameParenthesis(BinaryTreeNode*);

    BinaryTreeNode* NameParenthesisConstruction(string, int&);
    BinaryTreeNode* InorderPreorderConstruction(string, string, int&);
    BinaryTreeNode* InorderPostorderConstruction(string, string, int&);
    BinaryTreeNode* InorderLevelorderConstruction(string, string);
    BinaryTreeNode* LeftRightConstruction(string, int&);

    void InsertLevelOrder(BinaryTreeNode*, char, unordered_map<char, int>&);

    int TreeHeight(BinaryTreeNode*);
    int TreeCountNodes(BinaryTreeNode*);
    int TreeCountNonLeafNodes(BinaryTreeNode*);
    int TreeCountLeafNodes(BinaryTreeNode*);
    int TreeCountDeg1Nodes(BinaryTreeNode*);
    int TreeCountDeg2Nodes(BinaryTreeNode*);
};