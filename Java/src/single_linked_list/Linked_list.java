package single_linked_list;

import java.util.Objects;

class Node {
    int data;
    Node next;

    Node() {
        data = 0;
        next = null;
    }

    Node(int value) {
        data = value;
        next = null;
    }
}

class LinkedList {
    Node head;
    Node tail;
    int length;

    LinkedList() {
        head = null;
        tail = null;
        length = 0;
    }

    void insertBack(int value) {
        Node newNode = new Node(value);
        if (tail == null) {
            head = tail = newNode;
            length++;
        } else {
            tail.next = newNode;
            tail = newNode;
            length++;
        }
    }

    void insertFront(int value) {
        Node newNode = new Node(value);
        if (tail == null) {
            head = tail = newNode;
            length++;
        } else {
            newNode.next = head;
            head = newNode;
            length++;
        }
    }

    void deleteHead() {
        Node temp = head;
        head = head.next;
        temp = null;
        length--;
    }

    int getNthFromFront(int value) {
        if (value > length)
            return -1;
        else if (value == length)
            return tail.data;
        else {
            Node temp = head;
            value--;
            for (int i = 0; i < value; i++) {
                if (temp.next != null)
                    temp = temp.next;
                else
                    return -1;
            }
            int res = temp.data;
            return res;
        }
    }

    int getNthFromBack(int value) {
        value--;
        int id = length - value;
        return getNthFromFront(id);
    }

    boolean isTheSame(LinkedList linked) {
        if (length != linked.length)
            return false;
        else {
            Node temp = head;
            Node temp2 = linked.head;
            for (int i = 0; i < length; i++) {
                if (temp.data != temp2.data)
                    return false;
                temp = temp.next;
                temp2 = temp2.next;
            }
            return true;
        }
    }

    void printList() {
        Node temp = head;
        while (temp.next != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println(temp.data);
    }

    int getLength() {
        return length;
    }

    int deleteWithKey(int value) {
        Node temp = head;
        Node prev = head;
        int idx = 1;
        while (temp.next != null) {
            if (temp.data == value) {
                prev.next = temp.next;
                temp = null;
                length--;
                return idx;
            }
            prev = temp;
            temp = temp.next;
            idx++;
        }
        return -1;
    }

    void swapPair() {
        Node cur = head;
        Node prev = cur;
        cur = head.next;
        while (cur.next != null || prev.next != null) {
            int temp = prev.data;
            prev.data = cur.data;
            cur.data = temp;
            if (cur.next == null)
                return;
            prev = cur.next;
            cur = prev.next;
        }
    }

    void swapNode(Node node1, Node node2) {
        int temp = node1.data;
        node1.data = node2.data;
        node2.data = temp;
    }

    void reverseList() {
        if (head == null || head.next == null)
            return;
        Node prev = null;
        Node current = head;
        Node next = null;
        while (current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void insertInOrder(int value) {
        Node newNode = new Node(value);
        Node cur = head;
        Node prev = head;
        if (head == null && tail == null)
            head = tail = newNode;
        else {
            if (newNode.data > tail.data) {
                tail.next = newNode;
                tail = newNode;
            } else if (newNode.data < head.data) {
                newNode.next = head;
                head = newNode;
            } else if (newNode.data > head.data && newNode.data < tail.data) {
                while (cur.next != null) {
                    if (cur.data > newNode.data) {
                        prev.next = newNode;
                        newNode.next = cur;
                        return;
                    } else {
                        prev = cur;
                        cur = cur.next;
                    }
                }
            }
        }
    }

    void deleteNextNode(Node n) {
        Objects.requireNonNull(n);
        Node temp = n.next;
        boolean isTail = temp == tail;
        n.next = temp.next;
        temp = null;
        length--;
        if (isTail)
            tail = n;
    }

    void deleteEvenPositions() {
        if (length <= 1)
            return;
        Node cur = head.next;
        Node prv = head;
        while (cur != null) {
            deleteNextNode(prv);
            if (prv.next == null)
                break;
            cur = prv.next.next;
            prv = prv.next;
        }
    }

    void swapHeadAndTail() {
        Node temp = head.next;
        tail.next = temp;
        while (temp.next != tail)
            temp = temp.next;
        temp.next = head;
        head.next = null;
        temp = head;
        head = tail;
        tail = temp;
    }

    void liftRotate(int value) {
        if (value < 1)
            System.out.println("can not rotate less than one time");
        else if (value == length)
            return;
        else {
            if (value >= length)
                value = value % length;
            Node temp = head;
            for (int i = 0; i < value - 1; i++) {
                temp = temp.next;
            }
            tail.next = head;
            head = temp.next;
            tail = temp;
            tail.next = null;
        }
    }

    void deleteTail() {
        Node temp = head;
        Node temp2 = tail;
        while (temp.next != null) {
            temp2 = temp;
            temp = temp.next;
        }
        tail = temp;
        temp2.next = null;
        temp2 = null;
        length--;
    }

    void deleteNode(Node prev, Node cur) {
        if (prev == null) {
            head = cur.next;
            cur = null;
        } else {
            prev.next = cur.next;
            cur = null;
        }
    }

    void removeDuplicates() {
        int[] arr = new int[length];
        for (int i = 0; i < length; i++)
            arr[i] = 0;
        Node temp = head;
        Node prev = head;
        while (temp.next != null) {
            arr[temp.data]++;
            if (arr[temp.data] > 1) {
                deleteNextNode(prev);
                temp = prev.next;
            } else {
                if (temp.next == null)
                    prev = temp;
                else {
                    prev = temp;
                    temp = temp.next;
                }
            }
        }
        arr[temp.data]++;
        if (arr[temp.data] > 1)
            deleteNextNode(prev);
    }

    void removeLastOccurrence(int value) {
        Node cur = head.next;
        Node prev = head;
        while (cur.next != null) {
            if (cur.next.data == value) {
                prev = cur;
            }
            cur = cur.next;
        }
        deleteNextNode(prev);
    }

    void moveToEnd(int key) {
        Node pKey = head;
        Node pCrawl = head;
        while (pCrawl != null) {
            if (pCrawl != pKey && pCrawl.data != key) {
                int temp = pKey.data;
                pKey.data = pCrawl.data;
                pCrawl.data = temp;
                pKey = pKey.next;
            }
            if (pKey.data != key)
                pKey = pKey.next;
            pCrawl = pCrawl.next;
        }
    }

    int max(Node temp) {
        if (temp == null)
            return -1;
        return Math.max(temp.data, max(temp.next));
    }

    Node getHead() {
        return head;
    }

    void arrangeOddEven() {
        if (length <= 1)
            return;
        int len = length;
        if (length % 2 != 0)
            len--;
        len /= 2;
        int i = 0;
        for (Node cur = head.next, prv = head; i < len; i++) {
            insertBack(cur.data);
            deleteNextNode(prv);
            if (prv.next == null)
                break;
            cur = prv.next.next;
            prv = prv.next;
        }
    }

    void insertAlternating(LinkedList linked2) {
        Node cur1 = head;
        Node prev1 = null;
        Node cur2 = linked2.head;
        Node prev2 = null;
        while (cur1 != null && cur2 != null) {
            prev1 = cur1;
            prev2 = cur2;
            cur1 = cur1.next;
            cur2 = cur2.next;
            prev1.next = prev2;
            prev2.next = cur1;
        }
        if (cur1 == null && prev1 != null) {
            prev1.next = cur2;
        }
    }

    void addList(LinkedList linked2) {
        Node cur = head;
        Node cur2 = linked2.head;
        while (cur != null && cur2 != null) {
            cur.data = cur.data + cur2.data;
            if (cur.data >= 10) {
                if (cur.next != null) {
                    cur.data -= 10;
                    cur.next.data += 1;
                } else {
                    cur.data -= 10;
                    cur2.data += 1;
                }
            }
            cur = cur.next;
            cur2 = cur2.next;
        }
        if (cur.next == null)
            cur.next = cur2;
    }

    void removeAllRepeated() {
        Node cur = head.next;
        Node prev = head;
        while (cur != null) {
            if (prev.data == cur.data) {
                if (cur.next != null && cur.next.next != null) {
                    while (prev.data == cur.data) {
                        Node temp2 = cur;
                        cur = cur.next;
                        temp2 = null;
                    }
                    Node temp = prev;
                    prev = cur;
                    temp = null;
                    cur = prev.next;
                } else {
                    Node temp = cur;
                    cur = cur.next;
                    temp = null;
                    prev.next = cur;
                }
            } else {
                prev = cur;
                cur = cur.next;
            }
        }
    }

    void printBack(Node current) {

        if (current == null) {
            return;
        }
        printBack(current.next);
        System.out.print(current.data + " ");

    }

    void Delete_list() {
        head = null;

    }

}
