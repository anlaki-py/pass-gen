- [Features](#features)
- [For Linux](#for-linux)
- [For Windows 10/11](#for-windows-1011)

# Password Generator

A simple and efficient command-line tool for generating strong and secure passwords.

## Overview

The Password Generator is designed to help users create strong passwords with ease. It uses a combination of letters, digits, and punctuation symbols to generate passwords that are hard to crack. This tool is perfect for users who need to create a new password for their email, social media accounts, or any other platform requiring a secure password.

## Features

- **Customizable Password Length:** 
  Users can specify the length of the password they want to generate. If no length is specified, the tool uses a default length of 12 characters.

- **Secure Passwords:**
  The generated passwords are a mix of uppercase and lowercase letters, digits, and special characters, making them highly secure.

- **Logging:**
  Every generated password is logged into a file, allowing users to retrieve previously generated passwords if necessary.

- **Simple CLI Commands:**
  The tool offers simple command-line options to view the password log or clear it.

------

## For Linux:

### Prerequisites

- Python 3.x

For debian based didtros:

```bash
sudo apt install python3
```

### Installation

Jump to your home directory:

```bash
cd $HOME
```

1. Clone the repository to your local machine:

```bash
sudo apt update -y
sudo apt install git -y
git clone https://github.com/anlaki-py/password-gen.git
```

2. Navigate to the cloned repository:

```bash
cd password-gen
```

3. Run the installer to add the script to `$PATH` :
- ( install for all users )

```bash
chmod +x installer.sh
./installer.sh
```

### uninstall
The uninstaller script will delete itself along with the directory it's in.

```bash
./uninstaller.sh
```

### Usage

To generate a new password, simply use the command:

```bash
pass
```

- You will be prompted to enter a custom length for the password. If you press enter without specifying a length, the tool will generate a password with the default length of 12 characters.

### list of avaliable arguments:

| argument | description |
| ------ | ------ |
| pass cat | To view the log of generated passwords |
| pass clear | To clear the log file |
| pass help | For  help |

------

## For Windows 10/11
- In progress...
 
------

## Acknowledgments

- This tool was created as a simple solution for generating secure passwords. It is intended for personal use and is not recommended for generating passwords for highly sensitive accounts.
 
## License

#### anlaki
None.