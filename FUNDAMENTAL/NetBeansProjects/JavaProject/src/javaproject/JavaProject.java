
package javaproject;
public class JavaProject {
    public static void main(String[] args) {
       
        binarytree.BT binary1=new binarytree.BT( 10);
        
        binary1.add(14);
        binary1.add(8);
        binary1.add(9);
        binary1.add(12);
        binary1.add(11);
        binary1.add(5);
        
//        binary1.postprint(binary1.get_root());
//        System.out.println("");
//       
       System.out.println(binary1.gethight(binary1.get_root()));
        
        
    }
}
