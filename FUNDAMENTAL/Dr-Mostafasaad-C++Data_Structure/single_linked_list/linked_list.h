#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next;

public:
    node();
    node(int value);
};

class linked_list
{

private:
    node *head;
    node *tail;
    int length;

public:
    linked_list();
    ~linked_list();
    //////////////////////////////////////////////////////
    void insert_back(int value);
    void insert_front(int value);
    void insert_in_order(int value);
    void insert_alternatig(linked_list *linked2);
    ///////////////////////////////////////////////////////////////////

    //////////////////////////////////////////

    void delete_head();
    void delete_tail();
    int delete_with_key(int value);
    void delete_even_positions();
    void delete_next_node(node *node);
    ///////////////////////////////////////////////////////

    ////////////////////////////////////////////
    int get_nth_from_front(int value);
    int get_nth_from_back(int value);
    /////////////////////////////////////////////

    /////////////////////////////////////////////////
    bool is_the_same(linked_list *linked);
    //////////////////////////////////////////////

    ///////////////////////////////////////////////
    void print_list();
    /////////////////////////////////////////////////

    /////////////////////////////////
    int get_length();
    node *get_head();
    ///////////////////////////////

    /////////////////////////////////////////////////
    void swap_pair();
    void swap_node(node *node1, node *node2);
    void swap_head_and_tail();
    ///////////////////////////////////////////////////

    /////////////////////////////////////////////
    void remove_duplicates();
    void remove_last_occurance(int value);
    void remove_all_repeted();
    //////////////////////////////////////////////////////////

    //////////reverse list/////////////
    void reverse_list();
    /////////////////////////////////////////////

    ///////////////////////////////////////////
    void lift_rotate(int value);
    ////////////////////////////////////////////

    ///////////////////////////////////////////
    void moveToEnd(int value);
    ////////////////////////////////////////////

    ///////////////////////////////////////////
    int max(node *temp);
    ///////////////////////////////////////////

    ///////////////////////////////////////////
    void arrange_odd_even();
    ///////////////////////////////////////////

    ///////////////////////////////////////////
    void add_list(linked_list *linked2);
    ///////////////////////////////////////////

    ///////////////////////////////////////////
    void delete_node(node *prev, node *cur);
    ///////////////////////////////////////////
};