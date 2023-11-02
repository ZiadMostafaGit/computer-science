import binarytree as bt
# import turtle
if __name__ == "__main__":
        binary_tree = bt.BinaryTree(10)
        binary_tree.add_recursive(binary_tree.root, 5)
        binary_tree.add_recursive(binary_tree.root, 20)
        binary_tree.add_recursive(binary_tree.root, 6)
        binary_tree.add_recursive(binary_tree.root, 8)
        binary_tree.add_recursive(binary_tree.root, 15)
        binary_tree.add_recursive(binary_tree.root, 22)
        binary_tree.add_recursive(binary_tree.root, 7)
        binary_tree.add_recursive(binary_tree.root, 17)
        binary_tree.add_recursive(binary_tree.root, 30)

        print("inorder Traversal: ", end="")
        binary_tree.in_order_print(binary_tree.root)
        print()
        print("inorder Traversal: ", end="")
        binary_tree.print_inorder_iterative(binary_tree.root)
        print()
        
        
        
        
        
        
        
        
        
        # print("Max Value: ", binary_tree.get_max(binary_tree.root))
        # print("Tree Height: ", binary_tree.get_height(binary_tree.root))
        # print("Total Nodes: ", binary_tree.count_all_nodes(binary_tree.root))
        # print("Leaf Nodes: ", binary_tree.count_leaf_nodes(binary_tree.root))
        # print("Search for 12: ", "Found" if binary_tree.search_tree(binary_tree.root, 12) else "Not Found")
        # print("Is Perfect Binary Tree: ", "Yes" if binary_tree.is_perfect(binary_tree.root) else "No")
        # print("Preorder Traversal: ", end="")
        # binary_tree.pre_order_print(binary_tree.root)
        # print()
        # print("Inorder Traversal: ", end="")
        # binary_tree.in_order_print(binary_tree.root)
        # print()
        # binary_tree.add_recursive(binary_tree.root, 5)
        # binary_tree.add_recursive(binary_tree.root, 15)
        # binary_tree.add_recursive(binary_tree.root, 3)
        # binary_tree.add_recursive(binary_tree.root, 7)
        # binary_tree.add_recursive(binary_tree.root, 12)
        # binary_tree.add_recursive(binary_tree.root, 18)
        # binary_tree = bt.BinaryTree(10)
        # screen = turtle.Screen()
        # screen.setup(width=800, height=600)
        # screen.tracer(0)
        # turtle.speed(0)
        # turtle.hideturtle()
        # bt.draw_tree(turtle, binary_tree.root, 0, 200, 300, 100)
        # screen.update()
        # turtle.done()
            