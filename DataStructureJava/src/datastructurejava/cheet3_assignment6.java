package datastructurejava;

import java.util.Scanner;

public class cheet3_assignment6 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the first number: ");
        double num1 = scanner.nextDouble();

        System.out.print("Enter the second number: ");
        double num2 = scanner.nextDouble();

        double summation = num1 + num2;
        double difference = num1 - num2;
        double multiplication = num1 * num2;
        double division = num1 / num2;

        System.out.println("Num1 + Num2 = " + summation +
                "\nNum1 - Num2 = " + difference +
                "\nNum1 * Num2 = " + multiplication +
                "\nNum1 / Num2 = " + division);

        scanner.close();
    }
}
