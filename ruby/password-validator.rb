class PasswordValidator
  def initialize(password)
    @password = password
    @strength = 0
  end

  def validate_length
    if @password.length >= 5 && @password.length <= 9
      true
    elsif @password.length >= 10
      @strength += 2
      true
    else
      false
    end
  end

  def validate_special_chars(special_chars)
    if special_chars.chars.any? { |char| @password.include?(char) }
      @strength += 1
      true
    else
      false
    end
  end

  def validate_numbers(numbers_chars)
    if numbers_chars.chars.any? { |char| @password.include?(char) }
      @strength += 1
      true
    else
      false
    end
  end

  def validate_spaces
    !@password.include?(" ")
  end

  def display_password
    puts "Your entered password: #{@password}"
  end

  def summary(special_chars, numbers_chars)
    display_password
    if !validate_spaces
      puts "YOUR PASSWORD IS INVALID [CONTAINS SPACES]"
    else
      puts validate_numbers(numbers_chars) ? "Password contains numbers." : "Password does not contain any numbers."
      puts validate_special_chars(special_chars) ? "Password contains at least one special character." : "Password does not contain any special character."
      puts "Password has a normal or strong length." if validate_length
      puts "SUMMARY: YOUR PASSWORD STRENGTH IS #{@strength * 25} / 100%\n"
    end
  end
end

# Manually input password
print "Input your password: "
user_input_password = gets.chomp

# Define character sets
LOWERCASE_CHARS = "abcdefghijklmnopqrstuvwxyz"
UPPERCASE_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
NUMBERS = "0123456789"
SYMBOLS = "!@#$%^&*_=+-/"

# Validate the user-input password
validator = PasswordValidator.new(user_input_password)
validator.summary(SYMBOLS, NUMBERS)
