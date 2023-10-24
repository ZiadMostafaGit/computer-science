
package javaproject;
public class JavaProject {
    
    
    
    
    
    public static void main(String[] args) {
        binarytree.BT binary1=new binarytree.BT( 10);
        
        binary1.addRecursive(binary1.get_root(),14);
        binary1.addRecursive(binary1.get_root(),8);
         binary1.addRecursive(binary1.get_root(),9);
        binary1.addRecursive(binary1.get_root(),7);
         binary1.addRecursive(binary1.get_root(),11);
         binary1.addRecursive(binary1.get_root(),15);
//        binary1.add(4);
//        binary1.add(22);
//        binary1.add(0);
//        
//        binary1.add(110);
//        int res=binary1.countallnodes(binary1.get_root());
        System.out.println(binary1.gethight(binary1.get_root()));
       System.out.println(binary1.countallnodes(binary1.get_root()));
//       System.out.println(binary1.searchingtree(binary1.get_root(),12123));


        System.out.println(binary1.is_perfect(binary1.get_root()));


    }
}
