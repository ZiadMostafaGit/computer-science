
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
        binary1.add(4);
        binary1.add(22);
//        binary1.add(0);
        
        binary1.add(110);
        int res=binary1.countallnodes(binary1.get_root());
        res--;
        res/=2;
//       System.out.println(binary1.countallnodes(binary1.get_root()));
       System.out.println(res);

    }
}
