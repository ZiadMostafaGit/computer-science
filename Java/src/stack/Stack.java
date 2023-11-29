package stack;

import java.util.Arrays;

public class Stack<T> {
    private Object[] arr;
    private int top;
    private int size;

    public Stack(int sz) {
        arr = new Object[sz];
        top = -1;
        size = sz;
    }

    public boolean isFull() {
        return size == top + 1;
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public void push(T val) {
        if (isFull()) {
            resize();
        }
        top++;
        arr[top] = val;
    }

    public int getTop() {
        return top;
    }

    public void pop() {
        if (isEmpty()) {
            System.out.println("The stack is empty...!");
            return;
        }
        top--;
    }

    public T pick() {
        if (isEmpty()) {
            System.out.println("The stack is empty...!");
            return null;
        }
        return (T )arr[top];
    }

    public void print() {
        if (isEmpty()) {
            System.out.println("There are no elements to print..!");
            return;
        }
        for (int i = top; i >= 0; i--)
            System.out.print(arr[i] + " ");

        System.out.println();
    }

    private void resize() {
        Object[] newArr = Arrays.copyOf(arr, size * 2);
        size = size * 2;
        arr = newArr;
    }

    public void deleteStack() {
        top = -1;
    }

    public void reverse() {
        int j = 0;
        int i = top;
        while (i >= j) {
            T temp = (T) arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            j++;
            i--;
        }
    }

    public boolean isValidParentheses(String s) {
        int sz = s.length();
        int t = 0;
        for (int i = 1; i < sz; i++) {
            if (s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '[') {
                push((T) Character.valueOf(s.charAt(i)));
                t++;
            } else if (s.charAt(i) == ')' && s.charAt(t) == '(') {
                pop();
            } else if (s.charAt(i) == '{' && s.charAt(t) == '}') {
                pop();
            } else if (s.charAt(i) == ']' && s.charAt(t) == '[') {
                pop();
            }
        }
        return isEmpty();
    }

    public String removeAllAdjacentDuplicatesInString(String s) {
        int sz = s.length();

        for (int i = 0; i < sz; i++) {
            if (isEmpty()) {
                push((T) Character.valueOf(s.charAt(i)));
                continue;
            }
            if (s.charAt(i) == (char) arr[top]) {
                pop();
            } else {
                push((T) Character.valueOf(s.charAt(i)));
            }
        }
        StringBuilder newString = new StringBuilder(top + 1);
        for (int i = 0; i <= top; i++) {
            newString.append(arr[i]);
        }
        return newString.toString();
    }

    public int  asteroidCollision(int[] array, int sz) {
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < sz; i++) {
            if (array[i] < 0) {
                if (stack.isEmpty()) {
                    stack.push(array[i]);
                } else {
                    boolean tregar = true;

                    while (!stack.isEmpty()) {
                        if (stack.peek() > 0) {
                            if (Math.abs(array[i]) > stack.peek()) {
                                stack.pop();
                            } else if (Math.abs(array[i]) == stack.peek()) {
                                stack.pop();
                                tregar = false;
                                break;
                            } else if (Math.abs(array[i]) < stack.peek()) {
                                tregar = false;
                                break;
                            }
                        } else {
                            stack.push(array[i]);
                            tregar = false;
                            break;
                        }
                    }
                    if (tregar) {
                        stack.push(array[i]);
                    }
                }
            } else if (array[i] > 0) {
                stack.push(array[i]);
            }
        }

        // Print the result
        System.out.print("Result: ");
        while (!stack.isEmpty()) {
            System.out.print(stack.pop() + " ");
        }
    }

    public void printFront() {
        for (int i = 0; i <= top; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    public void insertAtBottom(T val, int pos) {
        if (pos == -1) {
            arr[0] = val;
            top++;
            return;
        }
        arr[pos + 1] = arr[pos];
        insertAtBottom(val, pos - 1);
    }

    public int scoreOfParentheses(String s) {
        int sz = s.length();
        int counter = 0;
        int counter2 = 0;
        for (int i = 0; i < sz; i++) {
            if (s.charAt(i) == '(' && s.charAt(i + 1) == ')') {
                counter++;
                i++;
            }

            if (s.charAt(i) == '(' && s.charAt(i + 1) == '(') {
                while (s.charAt(i) != ')' && s.charAt(i + 1) != ')') {
                    counter2++;
                    i += 2;
                }
                break;
            }
        }

        return (counter2 * 2) + counter;
    }
    
    public int getsize(){
        return size;
    }

}
