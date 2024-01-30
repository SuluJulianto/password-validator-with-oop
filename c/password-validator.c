#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100

struct PasswordValidator {
    char password[MAX_PASSWORD_LENGTH];
    int strength;
};

void initialize(struct PasswordValidator *validator, const char *password) {
    strncpy(validator->password, password, sizeof(validator->password));
    validator->password[sizeof(validator->password) - 1] = '\0';  // Null-terminate the string
    validator->strength = 0;
}

int validateLength(struct PasswordValidator *validator) {
    int length = strlen(validator->password);
    if (length >= 5 && length <= 9) {
        return 1;
    } else if (length >= 10) {
        validator->strength += 2;
        return 1;
    } else {
        return 0;
    }
}

int validateSpecialChars(struct PasswordValidator *validator, const char *specialChars) {
    if (strpbrk(validator->password, specialChars) != NULL) {
        validator->strength += 1;
        return 1;
    } else {
        return 0;
    }
}

int validateNumbers(struct PasswordValidator *validator, const char *numbersChars) {
    if (strpbrk(validator->password, numbersChars) != NULL) {
        validator->strength += 1;
        return 1;
    } else {
        return 0;
    }
}

int validateSpaces(struct PasswordValidator *validator) {
    if (strchr(validator->password, ' ') == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void displayPassword(const struct PasswordValidator *validator) {
    printf("Your entered password: %s\n", validator->password);
}

void summary(struct PasswordValidator *validator, const char *specialChars, const char *numbersChars) {
    displayPassword(validator);
    if (!validateSpaces(validator)) {
        printf("YOUR PASSWORD IS INVALID [CONTAINS SPACES]\n");
    } else {
        printf(validateNumbers(validator, numbersChars) ? "Password contains numbers.\n" : "Password does not contain any numbers.\n");
        printf(validateSpecialChars(validator, specialChars) ? "Password contains at least one special character.\n" : "Password does not contain any special character.\n");
        if (validateLength(validator)) {
            printf("Password has a normal or strong length.\n");
        }
        printf("SUMMARY: YOUR PASSWORD STRENGTH IS %d / 100%%\n", validator->strength * 25);
    }
}

int main() {
    // Manually input password
    char userInputPassword[MAX_PASSWORD_LENGTH];
    printf("Input your password: ");
    fgets(userInputPassword, sizeof(userInputPassword), stdin);
    userInputPassword[strcspn(userInputPassword, "\n")] = '\0';  // Remove newline character

    // Define character sets
    const char LOWERCASE_CHARS[] = "abcdefghijklmnopqrstuvwxyz";
    const char UPPERCASE_CHARS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char NUMBERS[] = "0123456789";
    const char SYMBOLS[] = "!@#$%^&*_=+-/";

    // Validate the user-input password
    struct PasswordValidator validator;
    initialize(&validator, userInputPassword);
    summary(&validator, SYMBOLS, NUMBERS);

    return 0;
}
