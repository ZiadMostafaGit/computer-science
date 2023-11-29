package single_linked_list;

// import java.util.*;

public class Main {
    public static void main(String[] args) {
        LinkedList linked1 = new LinkedList();
        LinkedList linked2 = new LinkedList();

        linked1.insertBack(1);
        linked1.insertBack(1);
        linked1.insertBack(1);
        linked1.insertBack(2);
        linked1.insertBack(2);
        linked1.insertBack(2);
        linked1.insertBack(2);
        linked1.insertBack(2);
        linked1.insertBack(2);
        linked1.insertBack(3);
        linked1.insertBack(3);
        linked1.insertBack(4);
        linked1.printList();
        linked1.insertBack(6);
        linked1.insertBack(7);
        linked1.insertBack(7);
        linked1.insertBack(5);
        linked1.insertBack(8);
        linked1.insertBack(9);
        linked1.insertBack(1);
        linked1.insertBack(10);
        linked1.insertBack(11);
        linked1.insertBack(12);
        linked1.insertBack(6);
        linked1.insertBack(70);
        linked1.insertBack(1);
        linked1.insertBack(1);
        linked1.insertBack(8);
        linked1.insertBack(9);
        linked1.insertBack(1);
        linked1.insertBack(1);
        linked1.insertBack(10);
        linked1.insertBack(11);
        linked1.insertBack(12);
        linked1.insertBack(12);
        linked1.printList();

        System.out.println(linked1.getNthFromFront(1));
        System.out.println(linked1.getNthFromFront(2));
        System.out.println(linked1.getNthFromFront(3));
        System.out.println(linked1.getNthFromFront(4));
        System.out.println(linked1.getNthFromFront(5));
        System.out.println(linked1.getNthFromFront(6));

        System.out.println(linked1.getNthFromBack(1));
        System.out.println(linked1.getNthFromBack(2));
        System.out.println(linked1.getNthFromBack(3));
        System.out.println(linked1.getNthFromBack(4));
        System.out.println(linked1.getNthFromBack(5));
        System.out.println(linked1.getNthFromBack(6));
        System.out.println(linked1.getLength());

        linked1.deleteHead();
        linked1.deleteHead();
        linked1.deleteHead();
        linked1.deleteHead();
        linked1.deleteHead();

        System.out.println(linked1.deleteWithKey(3));
        System.out.println(linked1.deleteWithKey(1));
        linked1.printList();

        linked2.insertBack(1);
        linked2.insertBack(2);
        linked2.insertBack(3);
        linked2.insertBack(4);
        linked2.insertBack(5);
        linked2.insertFront(6);
        linked2.insertFront(7);
        linked2.insertFront(9);
        linked2.insertFront(11);
        System.out.println(linked1.isTheSame(linked2));

        linked1.printList();
        linked2.printList();

        linked1.reverseList();

        linked1.deleteEvenPositions();
        linked1.printList();
        System.out.println(linked1.getLength());

        linked1.insertInOrder(1);
        linked1.insertInOrder(10);
        linked1.insertInOrder(20);
        linked1.insertInOrder(4);
        linked1.insertInOrder(17);
        linked1.insertInOrder(3);
        linked1.insertInOrder(22);
        linked1.insertInOrder(9);
        linked1.swapHeadAndTail();
        linked1.liftRotate(102);
        linked1.removeDuplicates();
        linked1.removeLastOccurrence(11);
        linked1.moveToEnd(1);
        System.out.println(linked1.max(linked1.getHead()));
        System.out.println(linked1.getLength());
        linked1.arrangeOddEven();
        linked1.printList();
        linked2.printList();
        linked1.addList(linked2);
//        linked1.insertAlternating(linked2);
        linked1.removeAllRepeated();
        linked1.printList();
        linked1.Delete_list();
        linked1.insertInOrder(4);
        linked1.insertInOrder(5);
        linked1.insertInOrder(1);
        linked1.insertInOrder(3);
        linked1.insertInOrder(66);
        linked1.insertInOrder(7);
        linked1.insertInOrder(55);
        linked1.insertInOrder(11);
        linked1.printList();
        linked1.printBack(linked1.getHead());
        linked1.insertFront(1);
        linked1.insertFront(2);
        linked1.insertFront(3);
        linked1.insertFront(4);
        linked1.insertFront(5);
        linked1.insertFront(6);
    }
}
