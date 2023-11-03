import helperfile as hf


# import turtle
class Node:
    def __init__(self, value):
        self.data = value
        self.left = None
        self.right = None


class BinaryTree:
    def __init__(self, value):
        self.root = Node(value)

    def add_recursive(self, current, value):
        if current is None:
            return Node(value)

        if value < current.data:
            current.left = self.add_recursive(current.left, value)
        elif value > current.data:
            current.right = self.add_recursive(current.right, value)

        return current

    def printBoundaryLeft(self, root):
        if root:
            if root.left:
                # to ensure top down order, print the node
                # before calling itself for left subtree
                print(root.data, end=" ")
                self.printBoundaryLeft(root.left)

            elif root.right:
                print(root.data, end=" ")
                self.printBoundaryLeft(root.right)

    def post_order_print(self, current):
        if current is None:
            return
        self.post_order_print(current.left)
        self.post_order_print(current.right)
        print(current.data, end=" ")

    def get_max(self, current):
        if current is None:
            return float("-inf")
        max_value = current.data
        left_max = self.get_max(current.left)
        right_max = self.get_max(current.right)

        return max(max_value, left_max, right_max)

    def get_height(self, current):
        if current is None:
            return 0
        return max(self.get_height(current.left), self.get_height(current.right)) + 1

    def count_all_nodes(self, current):
        if current is None:
            return 0
        return (
            self.count_all_nodes(current.left) + self.count_all_nodes(current.right) + 1
        )

    def count_leaf_nodes(self, current):
        if current is None:
            return 0
        if current.left is None and current.right is None:
            return 1
        return self.count_leaf_nodes(current.left) + self.count_leaf_nodes(
            current.right
        )

    def search_tree(self, current, value):
        if current is None:
            return False
        if current.data == value:
            return True
        return self.search_tree(current.left, value) or self.search_tree(
            current.right, value
        )

    def is_perfect(self, current):
        num = self.count_all_nodes(current)
        height = self.get_height(current) - 1
        return num == 2 ** (height + 1) - 1

    def pre_order_print(self, current):
        if current is None:
            return
        print(current.data, end=" ")
        self.pre_order_print(current.left)
        self.pre_order_print(current.right)

    def in_order_print(self, current):
        if current is None:
            return
        self.in_order_print(current.left)
        print(current.data, end=" ")
        self.in_order_print(current.right)

    def print_inorder_iterative(self, cur):
        nodes = []
        nodes.append((cur, False))

        while nodes:
            current, is_done = nodes.pop()

            if is_done:
                print(current.data, end=" ")
            else:
                if current.right:
                    nodes.append((current.right, False))

                nodes.append((current, True))

                if current.left:
                    nodes.append((current.left, False))
        print("\n")


#

# def draw_tree(turtle, node, x, y, x_dist, y_dist):
#     if node is not None:
#         turtle.penup()
#         turtle.goto(x, y)
#         turtle.pendown()
#         turtle.circle(20)
#         turtle.penup()
#         turtle.goto(x, y - 20)
#         turtle.pendown()
#         turtle.write(str(node.data), align="center", font=("Arial", 12, "normal"))

#         if node.left:
#             turtle.penup()
#             turtle.goto(x - x_dist, y - y_dist)
#             turtle.pendown()
#             turtle.goto(x, y)
#             draw_tree(turtle, node.left, x - x_dist, y - y_dist, x_dist / 2, y_dist - 50)

#         if node.right:
#             turtle.penup()
#             turtle.goto(x + x_dist, y - y_dist)
#             turtle.pendown()
#             turtle.goto(x, y)
#             draw_tree(turtle, node.right, x + x_dist, y - y_dist, x_dist / 2, y_dist - 50)

# Example usage
# if __name__ == "__main__":
# binary_tree = BinaryTree(10)
# binary_tree.add_recursive(binary_tree.root, 5)
# binary_tree.add_recursive(binary_tree.root, 15)
# binary_tree.add_recursive(binary_tree.root, 3)
# binary_tree.add_recursive(binary_tree.root, 7)
# binary_tree.add_recursive(binary_tree.root, 12)
# binary_tree.add_recursive(binary_tree.root, 18)
# screen = turtle.Screen()
# screen.setup(width=800, height=600)
# screen.tracer(0)
# turtle.speed(0)
# turtle.hideturtle()
# draw_tree(turtle, binary_tree.root, 0, 200, 300, 100)
# screen.update()
# turtle.done()


# #
#  def left_boundary(self, cur):
#         if self == None:
#             return
#         if cur.left:
#             print(cur.data, end=" ")

#         self.left_boundary(cur.left)
#         self.left_boundary(cur.right)
# #

# def left_boundary(self, cur):
#         if cur == None:
#             return
#         if cur.left:
#             print(cur.data, end=" ")
#             self.left_boundary(cur.left)

#         else:
#             self.left_boundary(cur.right)
