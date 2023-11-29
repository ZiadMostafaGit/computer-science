package array;

import java.util.Arrays;

public class Vector {
    private int capacity;
    private int[] arr;
    private int size;

    public Vector() {
        capacity = 100;
        arr = new int[capacity];
        size = 0;
    }

    public Vector(int si) {
        capacity = 100;
        if (si > capacity)
            capacity = si;
        size = 0;
        arr = new int[capacity];
    }

    public void push_back(int value) {
        if (size == capacity)
            double_capacity();
        arr[size] = value;
        size++;
    }

    private void double_capacity() {
        capacity *= 2;
        int[] new_arr = new int[capacity];
        for (int i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }
        arr = Arrays.copyOf(new_arr, capacity);
    }

    public void right_rotate() {
        if (size > 0) {
            int temp = arr[size - 1];
            for (int i = size - 1; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = temp;
        }
    }

    public void left_rotate() {
        if (size > 0) {
            int temp = arr[0];
            for (int i = 0; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            arr[size - 1] = temp;
        }
    }

    public void right_rotate_steps(int steps) {
        while (steps-- > 0) {
            right_rotate();
        }
    }

    public int pop(int idx) {
        if (idx >= 0 && idx < size) {
            int item = arr[idx];
            for (int i = idx; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
            return item;
        }
        return -1;
    }

    public int improved_search(int idx) {
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] == idx) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                return i;
            }
        }
        return -1;
    }

    public void print() {
        for (int i = 0; i < size; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
}
