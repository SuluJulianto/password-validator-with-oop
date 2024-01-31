#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100

struct PasswordValidator {
    char password[MAX_PASSWORD_LENGTH];
    int length_strength;
    int uppercase_strength;
    int lowercase_strength;
    int numbers_strength;
    int symbols_strength;
};

void initialize(struct PasswordValidator *validator, const char *password) {
    strncpy(validator->password, password, sizeof(validator->password));
    validator->password[sizeof(validator->password) - 1] = '\0';  // Null-terminate the string
    validator->length_strength = 0;
    validator->uppercase_strength = 0;
    validator->lowercase_strength = 0;
    validator->numbers_strength = 0;
    validator->symbols_strength = 0;
}

int validateLength(struct PasswordValidator *validator) {
    int length = strlen(validator->password);
    if (length >= 5 && length <= 9) {
        validator->length_strength = 1;
        return 1;
    } else if (length >= 10) {
        validator->length_strength = 2;
        return 1;
    } else {
        return 0;
    }
}

int validateSpecialChars(struct PasswordValidator *validator, const char *specialChars) {
    int count = 0;
    for (const char *ch = validator->password; *ch; ++ch) {
        if (strchr(specialChars, *ch) != NULL) {
            ++count;
        }
    }
    validator->symbols_strength = count;
    return count > 0;
}

int validateNumbers(struct PasswordValidator *validator, const char *numbersChars) {
    int count = 0;
    for (const char *ch = validator->password; *ch; ++ch) {
        if (strchr(numbersChars, *ch) != NULL) {
            ++count;
        }
    }
    validator->numbers_strength = count;
    return count > 0;
}

int validateSpaces(const struct PasswordValidator *validator) {
    return strchr(validator->password, ' ') == NULL;
}

void displayPassword(const struct PasswordValidator *validator) {
    printf("Your entered password: %s\n", validator->password);
}

void summary(struct PasswordValidator *validator, const char *specialChars, const char *numbersChars) {
    displayPassword(validator);

    if (!validateSpaces(validator)) {
        printf("YOUR PASSWORD IS INVALID [CONTAINS SPACES]\n");
        return;
    }

    if (validateLength(validator)) {
        printf("Password length is sufficient.\n");
    } else {
        printf("Password length is insufficient.\n");
    }

    if (validateNumbers(validator, numbersChars)) {
        printf("Password contains numbers.\n");
    } else {
        printf("Password does not contain any numbers.\n");
    }

    if (validateSpecialChars(validator, specialChars)) {
        printf("Password contains special characters.\n");
    } else {
        printf("Password does not contain any special characters.\n");
    }

    int total_strength = validator->length_strength + validator->numbers_strength +
                         validator->symbols_strength;
    printf("SUMMARY: YOUR PASSWORD STRENGTH IS %d / 100%%\n", total_strength * 25);
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
