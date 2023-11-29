package array;

public class vectormain {

        public static void main(String[] args) {
            Vector vector1 = new Vector(5);

            vector1.push_back(1);
            vector1.push_back(2);
            vector1.push_back(3);
            vector1.push_back(4);
            vector1.push_back(5);
            vector1.print();

            vector1.right_rotate();
            vector1.print();
            vector1.left_rotate();
            vector1.print();
            vector1.right_rotate_steps(3);
            vector1.print();

            System.out.println(vector1.pop(2));
            System.out.println(vector1.pop(3));
            vector1.print();
        }

    

}
