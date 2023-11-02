#include <iostream>
#include "binarytree.cpp"

int main()
{
    BinaryTree binaryTree(10);
    binaryTree.addRecursive(binaryTree.getRoot(), 5);
    binaryTree.addRecursive(binaryTree.getRoot(), 15);
    binaryTree.addRecursive(binaryTree.getRoot(), 3);
    binaryTree.addRecursive(binaryTree.getRoot(), 7);
    binaryTree.addRecursive(binaryTree.getRoot(), 12);
    binaryTree.addRecursive(binaryTree.getRoot(), 18);

    std::cout << "Postorder Traversal: ";
    binaryTree.postOrderPrint(binaryTree.getRoot());
    std::cout << std::endl;

    std::cout << "Max Value: " << binaryTree.getMax(binaryTree.getRoot()) << std::endl;
    std::cout << "Tree Height: " << binaryTree.getHeight(binaryTree.getRoot()) << std::endl;
    std::cout << "Total Nodes: " << binaryTree.countAllNodes(binaryTree.getRoot()) << std::endl;
    std::cout << "Leaf Nodes: " << binaryTree.countLeafNodes(binaryTree.getRoot()) << std::endl;

    std::cout << "Search for 12: " << (binaryTree.searchTree(binaryTree.getRoot(), 12) ? "Found" : "Not Found") << std::endl;
    std::cout << "Is Perfect Binary Tree: " << (binaryTree.isPerfect(binaryTree.getRoot()) ? "Yes" : "No") << std::endl;

    std::cout << "Preorder Traversal: ";
    binaryTree.preOrderPrint(binaryTree.getRoot());
    std::cout << std::endl;

    std::cout << "Inorder Traversal: ";
    binaryTree.inOrderPrint(binaryTree.getRoot());
    std::cout << std::endl;
    system("pause");
    return 0;
}
