import argparse
import random
import string
import os

def generate_strong_password(length):
    characters = string.ascii_letters + string.digits + string.punctuation
    password = ''.join(random.choice(characters) for i in range(length))
    return password

def main():
    # Set up the command line arguments
    parser = argparse.ArgumentParser(description="Generate a strong password.")
    parser.add_argument('length', type=int, help='Length of the generated password')

    args = parser.parse_args()  # This will automatically parse and return the command-line arguments

    custom_length = args.length  # Use the argument passed from the command line instead

    try:
        password = generate_strong_password(custom_length)

        print("Generated Password: \n")
        print(password, " \n")

        home_dir = os.path.expanduser('~')
        log_file_path = os.path.join(home_dir, "pass-gen/python/pass",  "pass.log")
        with open(log_file_path, "a") as file:
            file.write(password + "\n\n")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    main()