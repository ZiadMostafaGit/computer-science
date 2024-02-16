# Importing the DoublyLinkedList class from the previously defined file
from doubly_linked_list import DoublyLinkedList

if __name__ == "__main__":
    # Creating an instance of the DoublyLinkedList class
    linked1 = DoublyLinkedList()

    # Inserting elements at the head
    linked1.insert_head(5)
    linked1.insert_head(2)
    linked1.insert_head(22)
    linked1.insert_head(1)
    linked1.insert_head(6)
    linked1.insert_head(3)
    linked1.insert_head(11)
    linked1.insert_head(20)
    linked1.insert_head(9)
    linked1.insert_head(100)
    linked1.insert_head(60)
    linked1.insert_head(12)

    # Printing the list in both directions
    linked1.print_forward()
    linked1.print_backward()

    # Inserting elements at the tail
    linked1.insert_tail(5)
    linked1.insert_tail(2)
    linked1.insert_tail(22)
    linked1.insert_tail(1)
    linked1.insert_tail(6)
    linked1.insert_tail(3)
    linked1.insert_tail(11)
    linked1.insert_tail(20)
    linked1.insert_tail(9)
    linked1.insert_tail(100)
    linked1.insert_tail(60)
    linked1.insert_tail(12)

    # Printing the list in both directions
    linked1.print_forward()
    linked1.print_backward()

    # Inserting elements in sorted order
    linked1.insert_sorted(5)
    linked1.insert_sorted(2)
    linked1.insert_sorted(22)
    linked1.insert_sorted(1)
    linked1.insert_sorted(6)
    linked1.insert_sorted(3)
    linked1.insert_sorted(11)
    linked1.insert_sorted(20)
    linked1.insert_sorted(9)
    linked1.insert_sorted(100)
    linked1.insert_sorted(60)
    linked1.insert_sorted(12)

    # Printing the list in both directions
    linked1.print_forward()
    linked1.print_backward()

    # Deleting elements from the head and tail
    linked1.delete_head()
    linked1.delete_tail()
    linked1.delete_tail()
    linked1.delete_head()

    # Printing the list in both directions
    linked1.print_forward()
    linked1.print_backward()

    # Moving to a specific node and deleting it
    cur = linked1.move(3)
    linked1.delete_node(cur)

    # Printing the list in both directions
    linked1.print_forward()
    linked1.print_backward()

    # Deleting nodes with specific keys
    linked1.delete_node_with_key(1)
    linked1.delete_node_with_key(100)
    linked1.delete_node_with_key(20)
    linked1.delete_node_with_key(10000)

    # Printing the list in both directions
    linked1.print_forward()
    linked1.print_backward()

