#include "BinaryTree.hpp"
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

BinaryTree::BinaryTree(string inputString, int mode) {
    stringstream ss(inputString);
    constructionState = true;
    lCount = 0;
    rCount = 0;
    string a, b;
    int index = 0;
    switch(mode) {
    case 0: // Name-parenthesis representation
        root = NameParenthesisConstruction(inputString, index);
        break;
    case 1: // Inorder Preorder construction
        ss >> a;
        ss >> b;
        cout << "A: " << a << ", B: " << b << endl;
        root = InorderPreorderConstruction(a, b, index);
        break;
    case 2: // Inorder Postorder construction
        ss >> a;
        ss >> b;
        index = b.length() - 1;
        root = InorderPostorderConstruction(a, b, index);
        break;
    case 3: // Inorder Levelorder construction
        ss >> a;
        ss >> b;
        root = InorderLevelorderConstruction(a, b);
        break;
    case 4: // LeftRight construction
        ss >> a;
        cout << "A: " << a << endl;
        root = LeftRightConstruction(a, index);
        break;
    default:
        constructionState = false;
        break;
    }
    if (constructionState == false) {
        cout << "Construction failed" << endl;
        BinaryTreeNode::deleteTree(root);
        root = nullptr;
    }
}

void BinaryTree::Preorder(BinaryTreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}
void BinaryTree::Inorder(BinaryTreeNode* root){
    if (root == nullptr) {
            return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void BinaryTree::Postorder(BinaryTreeNode* root) {
    if (root == nullptr) {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

void BinaryTree::Levelorder(BinaryTreeNode* root) {
    if (root == nullptr) {
        return;
    }
    queue<BinaryTreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != nullptr) {
            q.push(temp->left);
        }
        if (temp->right != nullptr) {
            q.push(temp->right);
        }
    }
}

void BinaryTree::LeftRight(BinaryTreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << "(";
    LeftRight(root->left);
    cout << ")";
    LeftRight(root->right);
}
void BinaryTree::NameParenthesis(BinaryTreeNode* root) {
    if (root == nullptr) {
        cout << "()";
        return;
    }
    cout << root->data;
    cout << "(";
    NameParenthesis(root->left);
    NameParenthesis(root->right);
    cout << ")";
}

BinaryTreeNode* BinaryTree::NameParenthesisConstruction(string input, int& index) {
    cout << "Input: " << input << ", Index: " << index << endl;
    if (constructionState == false) {
        return nullptr;
    }
    if (input.length() <= index) {
        return nullptr;
    }
    if (input[index] != '(' && input[index] != ')') {
        BinaryTreeNode* temp = new BinaryTreeNode(string(1, input[index]));
        index++;
        if (input[index] == '(') {
            temp->left = NameParenthesisConstruction(input, ++index);
            temp->right = NameParenthesisConstruction(input, ++index);
            if (input[index] == ')') {
                index++;
            } else {
                constructionState = false;
                delete temp;
                return nullptr;
            }
        } else {
            constructionState = false;
            delete temp;
            return nullptr;
        }
        return temp;
    } else {
        if (input[index] == '(' && input[index + 1] == ')') {
            index++;
            return nullptr;
        } else {
            constructionState = false;
            return nullptr;
        }
    }
}

BinaryTreeNode* BinaryTree::InorderPreorderConstruction(string inorder, string preorder, int& preIndex) {
    
    if (constructionState == false) {
        return nullptr;
    }
    cout << "Inorder: " << inorder << ", Preorder: " << preorder << ", PreIndex: " << preIndex << endl;
    if (inorder.length() == 0) {
        return nullptr;
    }
    if (inorder.length() == 1) {
        cout << "Preorder id: " << preorder[preIndex] << ", Inorder 0: " << inorder[0] << endl;
        if (preorder[preIndex] == inorder[0]) {
            preIndex++;
            return new BinaryTreeNode(inorder.substr(0, 1));
        } else {
            constructionState = false;
            return nullptr;
        }
    }
    BinaryTreeNode* temp = new BinaryTreeNode(preorder.substr(preIndex, 1));
    int index = inorder.find(preorder[preIndex]);
    cout << "Index: " << index << endl;
    if (index == -1) {
        delete temp;
        constructionState = false;
        return nullptr;
    }
    preIndex++;
    temp->left = InorderPreorderConstruction(inorder.substr(0, index), preorder, preIndex);
    temp->right = InorderPreorderConstruction(inorder.substr(index + 1), preorder, preIndex);
    return temp;
}

BinaryTreeNode* BinaryTree::InorderPostorderConstruction(string inorder, string postorder, int& postIndex) {
    if (constructionState == false) {
        return nullptr;
    }
    cout << "Inorder: " << inorder << ", PostIndex: " << postorder << ", PostIndex: " << postIndex << endl;
    if (inorder.length() == 0) {
        return nullptr;
    }
    if (inorder.length() == 1) {
        cout << "Postorder id: " << postorder[postIndex] << ", Inorder 0: " << inorder[0] << endl;
        if (postorder[postIndex] == inorder[0]) {
            postIndex--;
            return new BinaryTreeNode(inorder.substr(0, 1));
        } else {
            constructionState = false;
            return nullptr;
        }
    }
    BinaryTreeNode* temp = new BinaryTreeNode(postorder.substr(postIndex, 1));
    int index = inorder.find(postorder[postIndex]);
    cout << "Index: " << index << endl;
    if (index == -1) {
        delete temp;
        constructionState = false;
        return nullptr;
    }
    postIndex--;
    temp->right = InorderPostorderConstruction(inorder.substr(index + 1), postorder, postIndex);
    temp->left = InorderPostorderConstruction(inorder.substr(0, index), postorder, postIndex);
    return temp;
}

BinaryTreeNode* BinaryTree::InorderLevelorderConstruction(string inorder, string levelOrder) {
    if (inorder.length() == 0) {
        return nullptr;
    }
    if (levelOrder.length() != inorder.length()) {
        constructionState = false;
        return nullptr;
    }
    unordered_map<char, int> indexTable;
    for (int i = 0; i < inorder.length(); i++) {
        indexTable[inorder[i]] = i;
    }
    BinaryTreeNode* root = new BinaryTreeNode(string(1, levelOrder[0]));
    for (int i = 1; i < levelOrder.length(); i++) {
        if (indexTable.find(levelOrder[i]) == indexTable.end()) {
            constructionState = false;
            return nullptr;
        }
        InsertLevelOrder(root, levelOrder[i], indexTable);
    }
    return root;
}
void BinaryTree::InsertLevelOrder(BinaryTreeNode* root, char data, unordered_map<char, int>& indexTable) {
    if (constructionState == false) {
        return;
    }
    int m = indexTable[(root->data)[0]];
    int n = indexTable[data];
    if (n < m) {
        if (root->left == nullptr) {
            root->left = new BinaryTreeNode(string(1, data));
        } else {
            InsertLevelOrder(root->left, data, indexTable);
        }
    } else if (n > m) {
        if (root->right == nullptr) {
            root->right = new BinaryTreeNode(string(1, data));
        } else {
            InsertLevelOrder(root->right, data, indexTable);
        }

    } else {
        constructionState = false;
        return;
    }
}

BinaryTreeNode* BinaryTree::LeftRightConstruction(string input, int& index) {
    if (constructionState == false) {
        return nullptr;
    }
    if (input.length() == index) {
        return nullptr;
    }
    if (input[index] == ')') {
        rCount++;
        return nullptr;
    }
    if (rCount > lCount) {
        constructionState = false;
        return nullptr;
    }
    if (input[index] != '(') {
        constructionState = false;
        return nullptr;
    }
    BinaryTreeNode* temp = new BinaryTreeNode(string(1, lCount + 'A'));
    lCount++;
    temp->left = LeftRightConstruction(input, ++index);
    temp->right = LeftRightConstruction(input, ++index);
    return temp;
}

int BinaryTree::TreeHeight(BinaryTreeNode* root) {
    if (root ==nullptr) return 0;
    int lH = TreeHeight(root->left);
    int rH = TreeHeight(root->right);
    return max(lH, rH) + 1;
}
int BinaryTree::TreeCountNodes(BinaryTreeNode* root) {
    if (root == nullptr) return 0;
    int lN = TreeCountNodes(root->left);
    int rN = TreeCountNodes(root->right);
    return 1 + lN + rN;
}
int BinaryTree::TreeCountNonLeafNodes(BinaryTreeNode* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) {
        return 0;
    } else {
        int lN = TreeCountNonLeafNodes(root->left);
        int rN = TreeCountNonLeafNodes(root->right);
        return 1 + lN + rN;
    }
}
int BinaryTree::TreeCountLeafNodes(BinaryTreeNode* root) {
    if (root == nullptr) return 0;
    int lN = TreeCountLeafNodes(root->left);
    int rN = TreeCountLeafNodes(root->right);
    if (lN == 0 && rN == 0) {
        return 1;
    }
    return lN + rN;
}
int BinaryTree::TreeCountDeg1Nodes(BinaryTreeNode* root) {
    if (root == nullptr) return 0;
    int lN = TreeCountDeg1Nodes(root->left);
    int rN = TreeCountDeg1Nodes(root->right);
    if (root->left != nullptr && root->right == nullptr) {
        return 1 + lN;
    } else if (root->left == nullptr && root->right != nullptr) {
        return 1 + rN;
    } else {
        return lN + rN;
    }
}
int BinaryTree::TreeCountDeg2Nodes(BinaryTreeNode* root) {
    if (root == nullptr) return 0;
    int lN = TreeCountDeg2Nodes(root->left);
    int rN = TreeCountDeg2Nodes(root->right);
    
    if (root->left != nullptr && root->right != nullptr) {
        return 1 + lN + rN;
    } else {
        return lN + rN;
    }
}

BinaryTree& BinaryTree::operator=(const BinaryTree& t) {
    if (this != &t) {
        if (!t.constructionState) return *this;
        BinaryTreeNode::deleteTree(root);
        root = BinaryTreeNode::Copy(t.root);
    }
    return *this;
}

void BinaryTree::NameParenthesisTraversal() {
    VALID_TREE();
    NameParenthesis(root);
    cout << endl;
}
void BinaryTree::PreorderTraversal() {
    VALID_TREE();
    Preorder(root);
    cout << endl;
}
void BinaryTree::InorderTraversal() {
    VALID_TREE();
    Inorder(root);
    cout << endl;
}
void BinaryTree::PostorderTraversal() {
    VALID_TREE();
    Postorder(root);
    cout << endl;
}
void BinaryTree::LevelorderTraversal() {
    VALID_TREE();
    Levelorder(root);
    cout << endl;
}
void BinaryTree::LeftRightTraversal() {
    VALID_TREE();
    LeftRight(root);
    cout << endl;
}

int BinaryTree::Height() {
    VALID_TREE_R(-1);
    return TreeHeight(root);
}
int BinaryTree::CountNodes() {
    VALID_TREE_R(-1);
    return TreeCountNodes(root);
}
int BinaryTree::CountNonLeafNodes() {
    VALID_TREE_R(-1);
    return TreeCountNonLeafNodes(root);
}
int BinaryTree::CountLeafNodes() {
    VALID_TREE_R(-1);
    return TreeCountLeafNodes(root);
}
int BinaryTree::CountDeg1Nodes() {
    VALID_TREE_R(-1);
    return TreeCountDeg1Nodes(root);
}
int BinaryTree::CountDeg2Nodes() {
    VALID_TREE_R(-1);
    return TreeCountDeg2Nodes(root);
}
bool operator==(const BinaryTree& t1, const BinaryTree& t2) {
    if (!t1.constructionState || !t2.constructionState) {
        return false;
    }
    return BinaryTreeNode::Equal(t1.root, t2.root);
}
bool operator!=(const BinaryTree& t1, const BinaryTree& t2) {
    if (!t1.constructionState || !t2.constructionState) {
        return true;
    }
    return !BinaryTreeNode::Equal(t1.root, t2.root);
}