#include <iostream>
#include "BinaryTree.cpp"
using namespace std;



int main() {
    BinaryTree t1("ABC BAC", 1);
    
    BinaryTree t2("ABC BAC", 1);
    

    BinaryTree t3("BACDEFGHIJ CBAEDJHFGI", 1);
    

    BinaryTree t4("(()())(())((()())())", 4);
    BinaryTree t5("A(B(C())D(E()F(G(H(I())J()))))", 4);
    BinaryTree t6("BCAEDHIGJF CBEIHJGFDA", 2);

    t1.NameParenthesisTraversal();
    t2.NameParenthesisTraversal();
    t3.NameParenthesisTraversal();
    t4.NameParenthesisTraversal();
    t5.NameParenthesisTraversal();
    t6.NameParenthesisTraversal();

    t3.PreorderTraversal();
    t4.PreorderTraversal();
    t3.InorderTraversal();
    t4.InorderTraversal();
    t3.PostorderTraversal();
    t4.PostorderTraversal();
    t3.LeftRightTraversal();
    t4.LeftRightTraversal();
    
    

    if (t1 == t2) {
        cout << "Equal" << endl;
    } else {
        cout << "Not Equal" << endl;
    }

    if (t3 == t4) {
        cout << "Equal" << endl;
    } else {
        cout << "Not Equal" << endl;
    }

    if (t4 == t6) {
        cout << "Equal" << endl;
    } else {
        cout << "Not Equal" << endl;
    }

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