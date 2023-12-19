
// package binarytreeinjava;
import java.util.ArrayDeque;
import java.util.Deque;

public class MainFile {

   
      public static void main(String[] args) {

                BinaryTree.BT root = new BinaryTree.BT(10);
                BinaryTree.node current = root.get_root();
                root.addRecursive(current, 5);
                root.addRecursive(current, 20);
                root.addRecursive(current, 6);
                root.addRecursive(current, 8);
                root.addRecursive(current, 15);
                root.addRecursive(current, 22);
                root.addRecursive(current, 7);
                root.addRecursive(current, 17);
                root.addRecursive(current, 30);
//                root.postprint(current);
//                System.out.println();
                // root.Left_boundary(current);
//                System.out.println(root.BT_Diameter(current));
//                root.Level_by_Level_Traversal(root);
//                System.out.println();
//                root.Level_by_Level_rec(current);

//                System.out.println();
                Deque<Integer>predeque=new ArrayDeque<>();
                Deque<Integer>indeque=new ArrayDeque<>();
                
                    predeque=root.PreOrderDeque(root);
                    indeque=root.InOrderDeque(root);
                    
                    for(Integer elemint:predeque){
                        System.out.print(elemint+" ");
                    }
                    System.out.println();
                    for(Integer elemint:indeque){
                        System.out.print(elemint+" ");
                    }
                    System.out.println();
                    
                    root.inorder_iterative();



//                System.out.println(root.gethight(current)-1);
        }
}
