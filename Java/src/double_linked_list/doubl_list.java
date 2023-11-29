package double_linked_list;

// import java.util.*;

class dnode {
    int data;
    dnode next;
    dnode prev;

    public dnode(int val) {
        data = val;
        next = prev = null;
    }
}

class doubl_list {
    dnode head;
    dnode tail;
    int length;

    public doubl_list() {
        head = tail = null;
        length = 0;
    }

    public void link(dnode first, dnode second) {
        if (first != null)
            first.next = second;
        if (second != null)
            second.prev = first;
    }

    public void insert_tail(int val) {
        dnode new_node = new dnode(val);
        if (tail == null) {
            head = tail = new_node;
            length++;
        } else {
            link(tail, new_node);
            tail = new_node;
            length++;
        }
    }

    public void insert_head(int val) {
        dnode new_node = new dnode(val);
        if (head == null) {
            head = tail = new_node;
            length++;
        } else {
            link(new_node, head);
            head = new_node;
            length++;
        }
    }

    public void insert_sorted(int val) {
        if (length == 0 || val < head.data)
            insert_head(val);
        else if (tail.data <= val)
            insert_tail(val);
        else if (val > head.data && val < tail.data) {
            dnode prev = head;
            for (dnode cur = head; cur != null; cur = cur.next) {
                if (val <= cur.data) {
                    dnode new_node = new dnode(val);
                    prev.next = new_node;
                    link(new_node, cur);
                    new_node.prev = prev;
                    length++;
                    return;
                }
                prev = cur;
            }
        }
    }

    public void print_front() {
        dnode cur = head;
        while (cur != null) {
            System.out.print(cur.data + " ");
            cur = cur.next;
        }
        System.out.println();
    }

    public void print_back() {
        dnode cur = tail;
        while (cur != null) {
            System.out.print(cur.data + " ");
            cur = cur.prev;
        }
        System.out.println();
    }

    public void delete_head() {
        if (head != null) {
            dnode temp = head;
            head = head.next;
            head.prev = null;
            temp = null;
        } else {
            System.out.println("the list is empty..!");
        }
    }

    public void delete_tail() {
        if (tail != null) {
            dnode temp = tail;
            tail = tail.prev;
            tail.next = null;
            temp = null;
        } else {
            System.out.println("the list is empty..!");
        }
    }

    public void delete_node(dnode cur) {
        link(cur.prev, cur.next);
        cur = null;
    }

    public dnode move(int val) {
        val--;
        dnode cur = head;
        while (val-- > 0)
            cur = cur.next;
        return cur;
    }

    public void delete_node_with_key(int val) {
        if (head.data == val)
            delete_head();
        else if (tail.data == val)
            delete_tail();
        else {
            for (dnode cur = head; cur != null; cur = cur.next) {
                if (cur.data == val) {
                    delete_node(cur);
                    return;
                }
            }
            System.out.println("this val " + val + " is not in the list");
        }
    }
}
