import random
import string
import os

def generate_strong_password(length):
    characters = string.ascii_letters + string.digits + string.punctuation
    password = ''.join(random.choice(characters) for i in range(length))
    return password

def main():
    custom_length = 12  # Default password length
    try:
        custom_length = int(input("Enter length: "))
    except ValueError:
        print("Invalid input. Using default length.", "(",custom_length, ")")

    password = generate_strong_password(custom_length)
    
    # Print the generated password
    print("Generated Password: \n")
    print(password, " \n") 
    # Log the generated password in pass.log
    home_dir = os.path.expanduser('~')
    log_file_path = os.path.join(home_dir, "password-gen",  "python", "pass", "pass.log")
    with open(log_file_path, "a") as file:
        file.write(password + "\n\n")

if __name__ == "__main__":
    main()

