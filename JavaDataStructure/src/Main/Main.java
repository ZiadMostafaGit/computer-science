
package Main;

public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here

//        System.out.println("hello world");
        binarytree.BT root=new binarytree.BT(10);
        binarytree.node current=root.get_root();
        root.addRecursive(current, 5);
        root.addRecursive(current, 20);
        root.addRecursive(current, 6);
        root.addRecursive(current, 8);
        root.addRecursive(current, 15);
        root.addRecursive(current, 22);
        root.addRecursive(current, 7);
        root.addRecursive(current, 17);
        root.addRecursive(current, 30);
        root.postprint(current);
        System.out.println();
        root.Left_boundary(current);
        System.out.println();

//        root.infexprint(current);
//        System.out.println();
//        root.inorder_iterative();
    }

}