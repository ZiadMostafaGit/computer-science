#include <iostream>
#include "binarytree.cpp"

int main()
{
    BinaryTree bt(10);
    Node *current = bt.getroot();
    bt.addRecursive(current, 5);
    bt.addRecursive(current, 20);
    bt.addRecursive(current, 6);
    bt.addRecursive(current, 8);
    bt.addRecursive(current, 15);
    bt.addRecursive(current, 22);
    bt.addRecursive(current, 7);
    bt.addRecursive(current, 17);
    bt.addRecursive(current, 30);
    // cout << bt.Get_Diametar(current) << endl;
    bt.Level_by_Level_iterative();

    // cout << "Postorder Traversal: ";
    // bt.postOrderPrint(current);
    // cout << endl;

    // cout << "Max Value: " << bt.getMax(current) << endl;
    // cout << "Tree Height: " << bt.getHeight(current) << endl;
    // cout << "Total Nodes: " << bt.countAllNodes(current) << endl;
    // cout << "Leaf Nodes: " << bt.countLeafNodes(current) << endl;

    // cout << "Search for 12: " << (bt.searchTree(current, 12) ? "Found" : "Not Found") << endl;
    // cout << "Is Perfect Binary Tree: " << (bt.isPerfect(current) ? "Yes" : "No") << endl;

    // cout << "Preorder Traversal: ";
    // bt.preOrderPrint(current);
    // cout << endl;

    // cout << "Inorder Traversal: ";
    // bt.inOrderPrint(current);
    // cout << endl;
    //    system("pause");
    return 0;
}
