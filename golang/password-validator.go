package main

import (
	"fmt"
	"strings"
)

type PasswordValidator struct {
	password string
	strength int
}

func NewPasswordValidator(password string) *PasswordValidator {
	return &PasswordValidator{password: password, strength: 0}
}

func (pv *PasswordValidator) validateLength() bool {
	length := len(pv.password)
	if length >= 5 && length <= 9 {
		pv.strength += 1
		return true
	} else if length >= 10 {
		pv.strength += 2
		return true
	}
	return false
}

func (pv *PasswordValidator) validateSpecialChars(specialChars string) bool {
	for _, char := range pv.password {
		if strings.ContainsRune(specialChars, char) {
			pv.strength += 1
			return true
		}
	}
	return false
}

func (pv *PasswordValidator) validateNumbers(numbersChars string) bool {
	for _, char := range pv.password {
		if strings.ContainsRune(numbersChars, char) {
			pv.strength += 1
			return true
		}
	}
	return false
}

func (pv *PasswordValidator) validateSpaces() bool {
	return !strings.ContainsRune(pv.password, ' ')
}

func (pv *PasswordValidator) displayPassword() {
	fmt.Printf("Your entered password: %s\n", pv.password)
}

func (pv *PasswordValidator) summary(specialChars, numbersChars string) {
	pv.displayPassword()
	if !pv.validateSpaces() {
		fmt.Println("YOUR PASSWORD IS INVALID [CONTAINS SPACES]")
	} else {
		if pv.validateNumbers(numbersChars) {
			fmt.Println("Password contains numbers.")
		} else {
			fmt.Println("Password does not contain any numbers.")
		}

		if pv.validateSpecialChars(specialChars) {
			fmt.Println("Password contains at least one special character.")
		} else {
			fmt.Println("Password does not contain any special character.")
		}

		if pv.validateLength() {
			fmt.Println("Password has a normal or strong length.")
		}

		fmt.Printf("SUMMARY: YOUR PASSWORD STRENGTH IS %d / 100%%\n", pv.strength*25)
	}
}

func main() {
	// Manually input password
	fmt.Print("Input your password: ")
	var user_input_password string
	fmt.Scanln(&user_input_password)

	// Define character sets
	const LOWERCASE_CHARS = "abcdefghijklmnopqrstuvwxyz"
	const UPPERCASE_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	const NUMBERS = "0123456789"
	const SYMBOLS = "!@#$%^&*_=+-/"

	// Validate the user-input password
	validator := NewPasswordValidator(user_input_password)
	validator.summary(SYMBOLS, NUMBERS)
}
