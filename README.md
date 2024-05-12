# Password Generator

A simple and efficient command-line tool for generating strong and secure passwords.

## Overview

The Password Generator is designed to help users create strong passwords with ease. It uses a combination of letters, digits, and punctuation symbols to generate passwords that are hard to crack. This tool is perfect for users who need to create a new password for their email, social media accounts, or any other platform requiring a secure password.

## Features

- **Customizable Password Length:** Users can specify the length of the password they want to generate. If no length is specified, the tool uses a default length of 12 characters.
- **Secure Passwords:** The generated passwords are a mix of uppercase and lowercase letters, digits, and special characters, making them highly secure.
- **Logging:** Every generated password is logged into a file, allowing users to retrieve previously generated passwords if necessary.
- **Simple CLI Commands:** The tool offers simple command-line options to view the password log or clear it.

## Getting Started

### Prerequisites

- Python 3.x

For debian based systems:

```bash
sudo apt install python3
```


### Installation

Jump to your home directory:

```bash
cd ~
```

1. Clone the repository to your local machine:
```bash
sudo apt update -y
sudo apt install git -y
git clone https://github.com/anlaki-py/password-gen.git
ls
```

2. Navigate to the cloned repository:
```bash
cd password-gen
```

### Usage

Make the bash script executable:

```bash
chmod +x pass.sh
```

To generate a new password, simply run the bash script:

```bash
./pass.sh
```

You will be prompted to enter a custom length for the password. If you press enter without specifying a length, the tool will generate a password with the default length of 12 characters.

To view the log of generated passwords, use the following command:

```bash
./pass.sh cat
```

To clear the log file, use the following command:

```bash
./pass.sh clear
```

## Acknowledgments

- This tool was created as a simple solution for generating secure passwords. It is intended for personal use and is not recommended for generating passwords for highly sensitive accounts.
