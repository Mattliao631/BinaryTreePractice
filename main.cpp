#include <iostream>
#include "BinaryTree.cpp"
using namespace std;



int main() {
    BinaryTree t1("ABDC BADC", 1);
    BinaryTree t2("ABCD DBAC", 1);
    BinaryTree t3("BACDEFGHIJ CBAEDJHFGI", 1);
    BinaryTree t4("(()())(())((()())())", 4);
    BinaryTree t5("A(B(()C(()()))D(E(()())F(G(H(()I(()()))J(()()))())))", 0);
    BinaryTree t6("BCAEDHIGJF CBEIHJGFDA", 2);
    BinaryTree t7("AGCDFBE DCEABGF", 3);
    BinaryTree t8("BCAEDHIGJF ABDCEFGHJI", 3);

    cout << "All name traversals" << endl;
    t1.NameParenthesisTraversal();
    t2.NameParenthesisTraversal();
    t3.NameParenthesisTraversal();
    t4.NameParenthesisTraversal();
    t5.NameParenthesisTraversal();
    t6.NameParenthesisTraversal();
    t7.NameParenthesisTraversal();
    t8.NameParenthesisTraversal();

    cout << "T3 T4 traversals" << endl;
    cout << "Preorder: " << endl;
    t3.PreorderTraversal();
    t4.PreorderTraversal();
    cout << "Inorder: " << endl;
    t3.InorderTraversal();
    t4.InorderTraversal();
    cout << "Postorder: " << endl;
    t3.PostorderTraversal();
    t4.PostorderTraversal();
    cout << "Levelorder: " << endl;
    t3.LevelorderTraversal();
    t4.LevelorderTraversal();
    cout << "LeftRight: " << endl;
    t3.LeftRightTraversal();
    t4.LeftRightTraversal();
    
    cout << "T5" << endl;
    t5.LevelorderTraversal();
    
    cout << "T7" << endl;
    t7.LevelorderTraversal();
    t7.InorderTraversal();
    t7.PostorderTraversal();
    t7.PreorderTraversal();
    t7.LeftRightTraversal();


    cout << "T1, T2 ";
    if (t1 == t2) {
        cout << "Equal" << endl;
    } else {
        cout << "Not Equal" << endl;
    }

    cout << "T3, T4 ";
    if (t3 == t4) {
        cout << "Equal" << endl;
    } else {
        cout << "Not Equal" << endl;
    }

    cout << "T4, T6 ";
    if (t4 == t6) {
        cout << "Equal" << endl;
    } else {
        cout << "Not Equal" << endl;
    }
    
    cout <<"T4, T8 ";
    if (t4 == t8) {
        cout << "Equal" << endl;
    } else {
        cout << "Not Equal" << endl;
    }

    cout << "T4, T5 ";
    if (t4 == t5) {
        cout << "Equal" << endl;
    } else {
        cout << "Not Equal" << endl;
    }

    cout << "T3, T4 Structures" << endl;
    cout << "Height: " << t3.Height() << endl;
    cout << "Height: " << t4.Height() << endl;
    cout << "CountNodes: " << t3.CountNodes() << endl;
    cout << "CountNodes: " << t4.CountNodes() << endl;
    cout << "CountNonLeafNodes: " << t3.CountNonLeafNodes() << endl;
    cout << "CountNonLeafNodes: " << t4.CountNonLeafNodes() << endl;
    cout << "CountLeafNodes: " << t3.CountLeafNodes() << endl;
    cout << "CountLeafNodes: " << t4.CountLeafNodes() << endl;
    cout << "CountDeg1Nodes: " << t3.CountDeg1Nodes() << endl;
    cout << "CountDeg1Nodes: " << t4.CountDeg1Nodes() << endl;
    cout << "CountDeg2Nodes: " << t3.CountDeg2Nodes() << endl;
    cout << "CountDeg2Nodes: " << t4.CountDeg2Nodes() << endl;
    
}