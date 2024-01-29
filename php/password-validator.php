<?php

class PasswordValidator {
    private $password;
    private $strength;

    public function __construct($password) {
        $this->password = $password;
        $this->strength = 0;
    }

    public function validateLength() {
        if (strlen($this->password) >= 5 && strlen($this->password) <= 9) {
            return true;
        } elseif (strlen($this->password) >= 10) {
            $this->strength += 2;
            return true;
        } else {
            return false;
        }
    }

    public function validateSpecialChars($specialChars) {
        if (strpbrk($this->password, $specialChars) !== false) {
            $this->strength += 1;
            return true;
        } else {
            return false;
        }
    }

    public function validateNumbers($numbersChars) {
        if (strpbrk($this->password, $numbersChars) !== false) {
            $this->strength += 1;
            return true;
        } else {
            return false;
        }
    }

    public function validateSpaces() {
        if (strpos($this->password, ' ') === false) {
            return true;
        } else {
            return false;
        }
    }

    public function displayPassword() {
        echo "Your entered password: {$this->password}\n";
    }

    public function summary($specialChars, $numbersChars) {
        $this->displayPassword();
        if (!$this->validateSpaces()) {
            echo "YOUR PASSWORD IS INVALID [CONTAINS SPACES]\n";
        } else {
            echo $this->validateNumbers($numbersChars) ? "Password contains numbers.\n" : "Password does not contain any numbers.\n";
            echo $this->validateSpecialChars($specialChars) ? "Password contains at least one special character.\n" : "Password does not contain any special character.\n";
            if ($this->validateLength()) {
                echo "Password has a normal or strong length.\n";
            }
            echo "SUMMARY: YOUR PASSWORD STRENGTH IS " . ($this->strength * 25) . " / 100%\n";
        }
    }
}

// Manually input password
echo "Input your password: ";
$userInputPassword = trim(fgets(STDIN));

// Define character sets
$LOWERCASE_CHARS = "abcdefghijklmnopqrstuvwxyz";
$UPPERCASE_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
$NUMBERS = "0123456789";
$SYMBOLS = "!@#$%^&*_=+-/";

// Validate the user-input password
$validator = new PasswordValidator($userInputPassword);
$validator->summary($SYMBOLS, $NUMBERS);

?>
