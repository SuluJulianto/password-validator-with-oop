class PasswordValidator:
    def __init__(self, password):
        self.password = password
        self.strength = 0

    def validate_length(self):
        if 5 <= len(self.password) <= 9:
            return True
        elif len(self.password) >= 10:
            self.strength += 2
            return True
        else:
            return False

    def validate_special_chars(self, special_chars):
        if any(char in special_chars for char in self.password):
            self.strength += 1
            return True
        else:
            return False

    def validate_numbers(self, numbers_chars):
        if any(char in numbers_chars for char in self.password):
            self.strength += 1
            return True
        else:
            return False

    def validate_spaces(self):
        if " " not in self.password:
            return True
        else:
            return False

    def display_password(self):
        print(f"Your entered password: {self.password}")

    def summary(self, special_chars, numbers_chars):
        self.display_password()
        if not self.validate_spaces():
            print("YOUR PASSWORD IS INVALID [CONTAINS SPACES]")
        else:
            if self.validate_numbers(numbers_chars):
                print("Password contains numbers.")
            else:
                print("Password does not contain any numbers.")
            
            if self.validate_special_chars(special_chars):
                print("Password contains at least one special character.")
            else:
                print("Password does not contain any special character.")
            
            if self.validate_length():
                print("Password has a normal or strong length.")
            
            print(f"SUMMARY: YOUR PASSWORD STRENGTH IS {self.strength * 25} / 100%\n")


if __name__ == "__main__":
    # Manually input password
    user_input_password = input("Input your password: ")

    # Define character sets
    LOWERCASE_CHARS = "abcdefghijklmnopqrstuvwxyz"
    UPPERCASE_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    NUMBERS = "0123456789"
    SYMBOLS = "!@#$%^&*_=+-/"

    # Validate the user-input password
    validator = PasswordValidator(user_input_password)
    validator.summary(SYMBOLS, NUMBERS)
