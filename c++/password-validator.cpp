#include <iostream>
#include <cstring>

class PasswordValidator {
private:
    std::string password;
    int strength;

public:
    PasswordValidator(const std::string& password) : password(password), strength(0) {}

    bool validateLength() {
        size_t length = password.length();
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

    bool validateSpecialChars(const std::string& specialChars) {
        for (char ch : password) {
            if (specialChars.find(ch) != std::string::npos) {
                strength += 1;
                return true;
            }
        }
        return false;
    }

    bool validateNumbers(const std::string& numbersChars) {
        for (char ch : password) {
            if (numbersChars.find(ch) != std::string::npos) {
                strength += 1;
                return true;
            }
        }
        return false;
    }

    bool validateSpaces() {
        return password.find(' ') == std::string::npos;
    }

    void displayPassword() const {
        std::cout << "Your entered password: " << password << std::endl;
    }

    void summary(const std::string& specialChars, const std::string& numbersChars) {
        displayPassword();
        if (!validateSpaces()) {
            std::cout << "YOUR PASSWORD IS INVALID [CONTAINS SPACES]" << std::endl;
        } else {
            if (validateNumbers(numbersChars)) {
                std::cout << "Password contains numbers." << std::endl;
            } else {
                std::cout << "Password does not contain any numbers." << std::endl;
            }

            if (validateSpecialChars(specialChars)) {
                std::cout << "Password contains at least one special character." << std::endl;
            } else {
                std::cout << "Password does not contain any special character." << std::endl;
            }

            if (validateLength()) {
                std::cout << "Password has a normal or strong length." << std::endl;
            }

            std::cout << "SUMMARY: YOUR PASSWORD STRENGTH IS " << strength * 25 << " / 100%" << std::endl;
        }
    }
};

int main() {
    // Manually input password
    std::string user_input_password;
    std::cout << "Input your password: ";
    std::getline(std::cin, user_input_password);

    // Define character sets
    std::string LOWERCASE_CHARS = "abcdefghijklmnopqrstuvwxyz";
    std::string UPPERCASE_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string NUMBERS = "0123456789";
    std::string SYMBOLS = "!@#$%^&*_=+-/";

    // Validate the user-input password
    PasswordValidator validator(user_input_password);
    validator.summary(SYMBOLS, NUMBERS);

    return 0;
}
