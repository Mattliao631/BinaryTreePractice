#include "BinaryTree.hpp"
#include <sstream>
#include <string>
#include <iostream>
#include <queue>
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
            root = NameParenthesisConstruction(ss);
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
            root = InorderLevelorderConstruction(a, b, index);
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
    if (root == nullptr) return;

    cout << root->data;
    cout << "(";
    NameParenthesis(root->left);
    NameParenthesis(root->right);
    cout << ")";
}

BinaryTreeNode* BinaryTree::NameParenthesisConstruction(stringstream& ss) {
    return nullptr;
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

BinaryTreeNode* BinaryTree::InorderLevelorderConstruction(string inorder, string levelOrder, int& levelIndex) {
    queue<BinaryTreeNode*> q;
    q.push(new BinaryTreeNode(string(1, levelOrder[levelIndex])));
    
    while(!q.empty()) {
        BinaryTreeNode* temp = q.front();
        q.pop();
        int index = inorder.find(temp->data);
        if (index == -1) {
            constructionState = false;
            return nullptr;
        }
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
        BinaryTreeNode::deleteTree(root);
        root = BinaryTreeNode::Copy(t.root);
    }
    return *this;
}