class PasswordValidator {
    constructor(password) {
        this.password = password;
        this.strength = 0;
    }

    validateLength() {
        if (this.password.length >= 5 && this.password.length <= 9) {
            return true;
        } else if (this.password.length >= 10) {
            this.strength += 2;
            return true;
        } else {
            return false;
        }
    }

    validateSpecialChars(specialChars) {
        if (Array.from(specialChars).some(char => this.password.includes(char))) {
            this.strength += 1;
            return true;
        } else {
            return false;
        }
    }

    validateNumbers(numbersChars) {
        if (Array.from(numbersChars).some(char => this.password.includes(char))) {
            this.strength += 1;
            return true;
        } else {
            return false;
        }
    }

    validateSpaces() {
        if (!this.password.includes(" ")) {
            return true;
        } else {
            return false;
        }
    }

    displayPassword() {
        console.log(`Your entered password: ${this.password}`);
    }

    summary(specialChars, numbersChars) {
        this.displayPassword();
        if (!this.validateSpaces()) {
            console.log("YOUR PASSWORD IS INVALID [CONTAINS SPACES]");
        } else {
            if (this.validateNumbers(numbersChars)) {
                console.log("Password contains numbers.");
            } else {
                console.log("Password does not contain any numbers.");
            }

            if (this.validateSpecialChars(specialChars)) {
                console.log("Password contains at least one special character.");
            } else {
                console.log("Password does not contain any special character.");
            }

            if (this.validateLength()) {
                console.log("Password has a normal or strong length.");
            }

            console.log(`SUMMARY: YOUR PASSWORD STRENGTH IS ${this.strength * 25} / 100%\n`);
        }
    }
}

// Manually input password
const userInputPassword = prompt("Input your password:");

// Define character sets
const LOWERCASE_CHARS = "abcdefghijklmnopqrstuvwxyz";
const UPPERCASE_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const NUMBERS = "0123456789";
const SYMBOLS = "!@#$%^&*_=+-/";

// Validate the user-input password
const validator = new PasswordValidator(userInputPassword);
validator.summary(SYMBOLS, NUMBERS);
