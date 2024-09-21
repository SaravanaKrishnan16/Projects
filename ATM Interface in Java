import java.util.Scanner;

class Account {
    private String accountNumber;
    private String pin;
    private double balance;

    public Account(String accountNumber, String pin, double initialBalance) {
        this.accountNumber = accountNumber;
        this.pin = pin;
        this.balance = initialBalance;
    }

    public String getPin() {
        return pin;
    }

    public double getBalance() {
        return balance;
    }

    public void deposit(double amount) {
        balance += amount;
        System.out.printf("Deposited: ₹%.2f\n", amount);
    }

    public boolean withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            System.out.printf("Withdrawn: ₹%.2f\n", amount);
            return true;
        } else {
            System.out.println("Insufficient funds!");
            return false;
        }
    }
}

public class SimpleATM {
    private static Account account;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Create a sample account for demonstration
        account = new Account("123456", "1234", 5000.00); // Initial balance in INR

        System.out.println("Welcome to the ATM!");

        // User Authentication
        System.out.print("Enter Account Number: ");
        String inputAccountNumber = scanner.nextLine();
        System.out.print("Enter PIN: ");
        String inputPin = scanner.nextLine();

        if (!inputAccountNumber.equals(account.accountNumber) || !inputPin.equals(account.getPin())) {
            System.out.println("Invalid account number or PIN. Exiting...");
            return;
        }

        int choice;
        do {
            System.out.println("\nATM Menu:");
            System.out.println("1. Check Balance");
            System.out.println("2. Deposit Money");
            System.out.println("3. Withdraw Money");
            System.out.println("4. Exit");
            System.out.print("Choose an option: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.printf("Current Balance: ₹%.2f\n", account.getBalance());
                    break;
                case 2:
                    System.out.print("Enter amount to deposit: ₹");
                    double depositAmount = scanner.nextDouble();
                    account.deposit(depositAmount);
                    break;
                case 3:
                    System.out.print("Enter amount to withdraw: ₹");
                    double withdrawAmount = scanner.nextDouble();
                    account.withdraw(withdrawAmount);
                    break;
                case 4:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice! Please try again.");
            }
        } while (choice != 4);

        scanner.close();
    }
}
