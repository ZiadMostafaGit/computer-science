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

    //
    //    std::cout << "Postorder Traversal: ";
    //    bt.postOrderPrint(bt.getRoot());
    //    std::cout << std::endl;

    //    std::cout << "Max Value: " << bt.getMax(bt.getRoot()) << std::endl;
    //    std::cout << "Tree Height: " << bt.getHeight(bt.getRoot()) << std::endl;
    //    std::cout << "Total Nodes: " << bt.countAllNodes(bt.getRoot()) << std::endl;
    //    std::cout << "Leaf Nodes: " << bt.countLeafNodes(bt.getRoot()) << std::endl;
    //
    //    std::cout << "Search for 12: " << (bt.searchTree(bt.getRoot(), 12) ? "Found" : "Not Found") << std::endl;
    //    std::cout << "Is Perfect Binary Tree: " << (bt.isPerfect(bt.getRoot()) ? "Yes" : "No") << std::endl;
    //
    //    std::cout << "Preorder Traversal: ";
    //    bt.preOrderPrint(bt.getRoot());
    //    std::cout << std::endl;
    //
    //    std::cout << "Inorder Traversal: ";
    //    bt.inOrderPrint(bt.getRoot());
    //    std::cout << std::endl;
    //    system("pause");
    return 0;
}
