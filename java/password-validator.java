import java.util.Scanner;

public class PasswordValidator {
    private String password;
    private int strength;

    public PasswordValidator(String password) {
        this.password = password;
        this.strength = 0;
    }

    public boolean validateLength() {
        int length = password.length();
        if (length >= 5 && length <= 9) {
            strength += 1;
            return true;
        } else if (length >= 10) {
            strength += 2;
            return true;
        } else {
            return false;
        }
    }

    public boolean validateSpecialChars(String specialChars) {
        for (char ch : password.toCharArray()) {
            if (specialChars.contains(String.valueOf(ch))) {
                strength += 1;
                return true;
            }
        }
        return false;
    }

    public boolean validateNumbers(String numbersChars) {
        for (char ch : password.toCharArray()) {
            if (numbersChars.contains(String.valueOf(ch))) {
                strength += 1;
                return true;
            }
        }
        return false;
    }

    public boolean validateSpaces() {
        return !password.contains(" ");
    }

    public void displayPassword() {
        System.out.println("Your entered password: " + password);
    }

    public void summary(String specialChars, String numbersChars) {
        displayPassword();
        if (!validateSpaces()) {
            System.out.println("YOUR PASSWORD IS INVALID [CONTAINS SPACES]");
        } else {
            if (validateNumbers(numbersChars)) {
                System.out.println("Password contains numbers.");
            } else {
                System.out.println("Password does not contain any numbers.");
            }

            if (validateSpecialChars(specialChars)) {
                System.out.println("Password contains at least one special character.");
            } else {
                System.out.println("Password does not contain any special character.");
            }

            if (validateLength()) {
                System.out.println("Password has a normal or strong length.");
            }

            System.out.println("SUMMARY: YOUR PASSWORD STRENGTH IS " + strength * 25 + " / 100%");
        }
    }

    public static void main(String[] args) {
        // Manually input password
        Scanner scanner = new Scanner(System.in);
        System.out.print("Input your password: ");
        String user_input_password = scanner.nextLine();

        // Define character sets
        String LOWERCASE_CHARS = "abcdefghijklmnopqrstuvwxyz";
        String UPPERCASE_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String NUMBERS = "0123456789";
        String SYMBOLS = "!@#$%^&*_=+-/";

        // Validate the user-input password
        PasswordValidator validator = new PasswordValidator(user_input_password);
        validator.summary(SYMBOLS, NUMBERS);
    }
}
