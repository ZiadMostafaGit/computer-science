class DNode:
    def __init__(self, val):
        self.data = val
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0

    def link(self, first, second):
        if first:
            first.next = second
        if second:
            second.prev = first

    def insert_tail(self, val):
        new_node = DNode(val)

        if not self.tail:
            self.head = self.tail = new_node
            self.length += 1
        else:
            self.link(self.tail, new_node)
            self.tail = new_node
            self.length += 1

    def insert_head(self, val):
        new_node = DNode(val)
        if not self.head:
            self.head = self.tail = new_node
            self.length += 1
        else:
            self.link(new_node, self.head)
            self.head = new_node
            self.length += 1

    def insert_sorted(self, val):
        if self.length == 0 or val < self.head.data:
            self.insert_head(val)
        elif self.tail.data <= val:
            self.insert_tail(val)
        elif val > self.head.data and val < self.tail.data:
            prev = self.head
            for cur in self:
                if val <= cur.data:
                    new_node = DNode(val)
                    prev.next = new_node
                    self.link(new_node, cur)
                    new_node.prev = prev
                    self.length += 1
                    return
                prev = cur

    def delete_head(self):
        if self.head:
            temp = self.head
            self.head = self.head.next
            if self.head:
                self.head.prev = None
            del temp
            self.length -= 1
        else:
            print("The list is empty!")

    def delete_tail(self):
        if self.tail:
            temp = self.tail
            self.tail = self.tail.prev
            if self.tail:
                self.tail.next = None
            del temp
            self.length -= 1
        else:
            print("The list is empty!")

    def delete_node(self, cur):
        self.link(cur.prev, cur.next)
        del cur
        self.length -= 1

    def move(self, val):
        val -= 1
        cur = self.head
        while val > 0 and cur:
            cur = cur.next
            val -= 1
        return cur

    def delete_node_with_key(self, val):
        if self.head and self.head.data == val:
            self.delete_head()
        elif self.tail and self.tail.data == val:
            self.delete_tail()
        else:
            for cur in self:
                if cur.data == val:
                    self.delete_node(cur)
                    return
            print(f"The value {val} is not in the list")

    def __iter__(self):
        current = self.head
        while current:
            yield current
            current = current.next

    def print_forward(self):
        for node in self:
            print(node.data, end=" ")
        print()

    def print_backward(self):
        current = self.tail
        while current:
            print(current.data, end=" ")
            current = current.prev
        print()


# Example usage:
doubly_linked_list = DoublyLinkedList()
doubly_linked_list.insert_tail(1)
doubly_linked_list.insert_tail(2)
doubly_linked_list.insert_tail(5)
doubly_linked_list.insert_tail(22)
doubly_linked_list.print_forward()
doubly_linked_list.print_backward()

doubly_linked_list.insert_sorted(3)
doubly_linked_list.insert_sorted(7)
doubly_linked_list.insert_sorted(21)
doubly_linked_list.insert_sorted(4)
doubly_linked_list.print_forward()
doubly_linked_list.print_backward()

doubly_linked_list.delete_head()
doubly_linked_list.delete_tail()
doubly_linked_list.print_forward()
doubly_linked_list.print_backward()

doubly_linked_list.delete_node_with_key(7)
doubly_linked_list.print_forward()
doubly_linked_list.print_backward()

