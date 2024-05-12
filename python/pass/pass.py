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
        custom_length = int(input("Enter the custom length for the password: \n"))
    except ValueError:
        print("Invalid input. Using default password length.")

    password = generate_strong_password(custom_length)
    
    # Print the generated password
    print(" ")
    print("Generated Password:      ", password)
    print(" ")
    
    # Log the generated password in pass.txt
    log_file_path = os.path.join(os.path.expanduser("~"), "python", "pass", "pass.txt")
    with open(log_file_path, "a") as file:
        file.write(password + "\n\n")
        print("""
=> arguments: 

"cat" to view logs.
"clear" to clear logs.

        """)

if __name__ == "__main__":
    main()

