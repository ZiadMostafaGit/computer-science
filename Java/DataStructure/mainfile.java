// package Java.DataStructure;
package Java.DataStructure;
// import Java.DataStructure.binarytreefile;

public class mainfile {

        public static void main(String[] args) {

                binarytreefile.BT root = new binarytreefile.BT(10);
                binarytreefile.node current = root.get_root();
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
                // root.Left_boundary(current);
                System.out.println(root.BT_Diametar(current));
                System.out.println();

        }

}
