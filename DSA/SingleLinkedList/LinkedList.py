class Node:
    def __init__(self, value=0):
        self.data = value
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0

    def insert_back(self, value):
        new_node = Node(value)
        if not self.tail:
            self.head = self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node
        self.length += 1

    def insert_front(self, value):
        new_node = Node(value)
        if not self.tail:
            self.head = self.tail = new_node
        else:
            new_node.next = self.head
            self.head = new_node
        self.length += 1

    def delete_front(self):
        if not self.head:
            return
        temp = self.head
        self.head = self.head.next
        del temp
        self.length -= 1

    def get_nth_from_front(self, value):
        if value > self.length:
            return -1
        temp = self.head
        for _ in range(value - 1):
            if temp.next:
                temp = temp.next
            else:
                return -1
        return temp.data

    def get_nth_from_back(self, value):
        value -= 1
        idx = self.length - value
        return self.get_nth_from_front(idx)

    def get_length(self):
        return self.length

    def delete_with_key(self, value):
        temp = self.head
        prev = None
        idx = 1
        while temp:
            if temp.data == value:
                if prev is None:
                    self.head = temp.next
                else:
                    prev.next = temp.next
                del temp
                self.length -= 1
                return idx
            prev = temp
            temp = temp.next
            idx += 1
        return -1

    def is_the_same(self, linked):
        if self.length != linked.length:
            return False
        temp1, temp2 = self.head, linked.head
        for _ in range(self.length):
            if temp1.data != temp2.data:
                return False
            temp1, temp2 = temp1.next, temp2.next
        return True

    def print_list(self):
        temp = self.head
        while temp:
            print(temp.data, end=" ")
            temp = temp.next
        print()

    def swap_pair(self):
        cur = self.head
        while cur and cur.next:
            cur.data, cur.next.data = cur.next.data, cur.data
            cur = cur.next.next

    def reverse_list(self):
        prev, current, next_node = None, self.head, None
        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        self.head = prev

    def insert_in_order(self, value):
        new_node = Node(value)
        cur, prev = self.head, None

        if not self.head and not self.tail:
            self.head = self.tail = new_node
        else:
            while cur and new_node.data > cur.data:
                prev, cur = cur, cur.next

            if not prev:
                new_node.next = self.head
                self.head = new_node
            else:
                prev.next = new_node
                new_node.next = cur
                if not cur:
                    self.tail = new_node

    def delete_next_node(self, n):
        if n is None or not n.next:
            return
        temp = n.next
        n.next = temp.next
        del temp
        self.length -= 1

    def delete_even_positions(self):
        if self.length <= 1:
            return
        cur, prev = self.head.next, self.head
        while cur:
            self.delete_next_node(prev)
            if not prev.next:
                break
            cur = prev.next.next
            prev = prev.next

    def swap_head_and_tail(self):
        if not self.head or not self.head.next:
            return
        temp = self.head.next
        self.tail.next = temp
        while temp.next != self.tail:
            temp = temp.next
        temp.next = self.head
        self.head.next = None
        temp = self.head
        self.head = self.tail
        self.tail = temp

    def lift_rotate(self, value):
        if value < 1:
            print("Cannot rotate less than one time")
        elif value == self.length:
            return
        else:
            if value >= self.length:
                value = value % self.length
            temp = self.head
            for _ in range(value - 1):
                temp = temp.next
            self.tail.next = self.head
            self.head = temp.next
            self.tail = temp
            self.tail.next = None

    def delete_tail(self):
        if not self.head or self.head == self.tail:
            del self.head
            self.head = self.tail = None
            self.length = 0
            return
        temp, temp2 = self.head, None
        while temp.next:
            temp2 = temp
            temp = temp.next
        self.tail = temp2
        del temp
        self.length -= 1

    def delete_node(self, prev, cur):
        if prev is None:
            self.head = cur.next
        else:
            prev.next = cur.next
        del cur

    def remove_duplicates(self):
        arr = [0] * self.length
        temp = self.head
        prev = None
        while temp:
            arr[temp.data] += 1
            if arr[temp.data] > 1:
                self.delete_next_node(prev)
                temp = prev.next
            else:
                prev = temp
                temp = temp.next

    def remove_last_occurrence(self, value):
        cur, prev = self.head.next, self.head
        while cur.next:
            if cur.next.data == value:
                prev = cur
            cur = cur.next
        self.delete_next_node(prev)

    def move_to_end(self, key):
        p_key = self.head
        p_crawl = self.head
        while p_crawl:
            if p_crawl != p_key and p_crawl.data != key:
                p_key.data, p_crawl.data = p_crawl.data, p_key.data
                p_key = p_key.next
            if p_key.data != key:
                p_key = p_key.next
            p_crawl = p_crawl.next

    def max(self, temp):
        if temp is None:
            return -1
        return max(temp.data, self.max(temp.next))

    def arrange_odd_even(self):
        if self.length <= 1:
            return
        len_val = self.length
        if self.length % 2 != 0:
            len_val -= 1
        len_val //= 2
        i = 0
        cur, prev = self.head.next, self.head
        while i < len_val:
            self.insert_back(cur.data)
            self.delete_next_node(prev)
            if not prev.next:
                break
            cur = prev.next.next
            prev = prev.next
            i += 1

    def insert_alternating(self, linked2):
        cur1, prev1 = self.head, None
        cur2 = linked2.get_head()
        while cur1 and cur2:
            prev1 = cur1
            cur1 = cur1.next
            cur2.next = prev1.next
            prev1.next = cur2
            cur2 = cur2.next
        if cur2:
            prev1.next = cur2

    def add_list(self, linked2):
        cur = self.head
        cur2 = linked2.get_head()
        while cur and cur2:
            cur.data = cur.data + cur2.data
            if cur.data >= 10:
                if cur.next:
                    cur.data -= 10
                    cur.next.data += 1
                else:
                    cur.data -= 10
                    cur2.data += 1
            cur = cur.next
            cur2 = cur2.next
        if cur:
            cur.next = cur2

    def remove_all_repeated(self):
        cur = self.head
        prev = None
        while cur:
            if prev and prev.data == cur.data:
                self.delete_next_node(prev)
            else:
                prev = cur
            cur = cur.next


# Example usage:
linked1 = LinkedList()
linked2 = LinkedList()

# Test the insert_back function
linked1.insert_back(1)
linked1.insert_back(1)
linked1.insert_back(1)
linked1.insert_back(2)
linked1.insert_back(2)
linked1.insert_back(2)
linked1.insert_back(2)
linked1.insert_back(2)
linked1.insert_back(2)
linked1.insert_back(3)
linked1.insert_back(3)
linked1.insert_back(4)
linked1.print_list()
linked1.insert_back(6)
linked1.insert_back(7)
linked1.insert_back(7)
linked1.insert_back(5)
linked1.insert_back(8)
linked1.insert_back(9)
linked1.insert_back(1)
linked1.insert_back(10)
linked1.insert_back(11)
linked1.insert_back(12)
linked1.insert_back(6)
linked1.insert_back(70)
linked1.insert_back(1)
linked1.insert_back(1)
linked1.insert_back(8)
linked1.insert_back(9)
linked1.insert_back(1)
linked1.insert_back(1)
linked1.insert_back(10)
linked1.insert_back(11)
linked1.insert_back(12)
linked1.insert_back(12)
linked1.print_list()

# Test the get_nth_from_front function
print(linked1.get_nth_from_front(1))
print(linked1.get_nth_from_front(2))
print(linked1.get_nth_from_front(3))
print(linked1.get_nth_from_front(4))
print(linked1.get_nth_from_front(5))
print(linked1.get_nth_from_front(6))

# Test the get_nth_from_back function
print(linked1.get_nth_from_back(1))
print(linked1.get_nth_from_back(2))
print(linked1.get_nth_from_back(3))
print(linked1.get_nth_from_back(4))
print(linked1.get_nth_from_back(5))
print(linked1.get_nth_from_back(6))
print(linked1.get_length())

# Test the delete function
linked1.delete_front()
linked1.delete_front()
linked1.delete_front()
linked1.delete_front()
linked1.print_list()

# Test the delete_with_key function
print(linked1.delete_with_key(3))
print(linked1.delete_with_key(1))
linked1.print_list()

# Test the is_the_same function
linked2.insert_back(1)
linked2.insert_back(2)
linked2.insert_back(3)
linked2.insert_back(4)
linked2.insert_back(5)
linked2.insert_front(6)
linked2.insert_front(7)
linked2.insert_front(9)
linked2.insert_front(11)
print(linked1.is_the_same(linked2))

# Test the swap_pair function
linked1.swap_pair()
linked1.print_list()
linked2.print_list()

# Test the reverse_list function
linked1.reverse_list()
linked1.print_list()

# Test the delete_even_positions function
linked1.delete_even_positions()
linked1.print_list()
print(linked1.get_length())

# Test the insert_in_order function
linked1.insert_in_order(1)
linked1.insert_in_order(10)
linked1.insert_in_order(20)
linked1.insert_in_order(4)
linked1.insert_in_order(17)
linked1.insert_in_order(3)
linked1.insert_in_order(22)
linked1.insert_in_order(9)
linked1.swap_head_and_tail()
linked1.lift_rotate(102)
linked1.remove_duplicates()
linked1.remove_last_occurrence(11)
linked1.move_to_end(1)
print(linked1.max(linked1.get_head()))
print(linked1.get_length())
linked1.arrange_odd_even()
linked1.print_list()
linked2.print_list()
linked1.add_list(linked2)
linked1.insert_alternating(linked2)
linked1.remove_all_repeated()
linked1.print_list()

