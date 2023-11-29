package stack;

// import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Stack<Integer> s1 = new Stack<>(10);

        // Uncomment the following section for testing with user input
        // Scanner scanner = new Scanner(System.in);
        // String s = scanner.nextLine();
        // int size = s.length();
        // for (int i = 0; i < size; i++) {
        // if (s.charAt(i) != ' ') {
        // s1.push((int) s.charAt(i));
        // } else {
        // s1.print();
        // s1.deleteStack();
        // }
        // }
        // s1.print();

        s1.push(10);
        s1.push(2);
        s1.push(-5);
        s1.push(40);
        s1.push(50);
        s1.push(60);
        s1.push(70);
        s1.print();
        s1.reverse();
        s1.print();
        int sz=3;
        int []arr={10,2,-5};
        s1.asteroidCollision((T)arr, sz);

        // Uncomment the following section for testing Valid_Parentheses
        // String s = "()()()(()()){}{}(((()))}([])()[]{}{[]}";
        // System.out.println(s1.isValidParentheses(s));

        // Uncomment the following section for testing
        // RemoveAllAdjacentDuplicatesInString
        // String s = "aabbaaccddsssabdehh";
        // String res = s1.removeAllAdjacentDuplicatesInString(s);
        // System.out.println(res);

        // Uncomment the following section for testing Asteroid_Collision
        // int[] arr = {-1, 3, 2, -5, 4};
        // s1.asteroidCollision(arr, 5);
        // s1.printFront();

        // Uncomment the following section for testing insert_at_bottom
        // s1.push(1);
        // s1.push(2);
        // s1.push(3);
        // s1.push(4);
        // s1.push(5);
        // int top = s1.getTop();
        // s1.insertAtBottom(6, top);
        // s1.printFront();

        // Uncomment the following section for testing Score_of_Parentheses
        // String s = "()((())())";
        // System.out.println(s1.scoreOfParentheses(s));
    }
}