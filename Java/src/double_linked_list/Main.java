package double_linked_list;

public class Main {
    public static void main(String[] args) {
        doubl_list list = new doubl_list();
        list.insert_tail(1);
        list.insert_tail(2);
        list.insert_tail(3);
        list.insert_head(0);
        list.insert_sorted(5);
        list.print_front();
        list.print_back();
        list.delete_head();
        list.delete_tail();
        list.print_front();
        list.delete_node_with_key(2);
        list.print_front();
    }
}
