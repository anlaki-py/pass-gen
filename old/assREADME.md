- [Features](#features)
- [For Linux](#for-linux)
- [For Windows 10/11](#for-windows-1011)

# [DEMO] PASS-GEN

pass-gen is a simple and efficient command-line tool for generating strong and secure passwords.

## Overview

pass-gen is designed to help users create strong passwords with ease. It uses a combination of letters, digits, and punctuation symbols to generate passwords that are hard to crack. This tool is perfect for users who need to create a new password for their email, social media accounts, or any other platform requiring a secure password.

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

1. Update & install Git:

```bash
sudo apt update -y
sudo apt install git -y
```

2. Clone the repository to your local machine:

```bash
git clone https://github.com/anlaki-py/pass-gen.git
```

3. Navigate to the cloned repository:

```bash
cd pass-gen
```

4. Run the installer to add the script to `$PATH` :
- ( install for all users )

```bash
# make installer.sh executable.
chmod +x installer.sh
./installer.sh
```

### Usage

To generate a new password, simply use the 
command `pass` followed by the length [required]:

```bash
# replace <length> with a number. 
pass <length>
```

### list of avaliable arguments:

- Simply use the command `pass` followed by the argument. 


| _argument_ | _description_                             |
| ----       | ----                                      |
| `{lenght}` | a number to specify the length [required] |
| `cat`      | To view the log of generated passwords    |
| `clear`    | To delete the log file                    |
| `help`     | For  help                                 |


### uninstall
The uninstaller script will delete itself along with the directory it's in.

```bash
./uninstaller.sh
```

------

## For Windows 10/11
- In progress...
 
------

## Acknowledgments

- This tool was created as a simple solution for 
generating secure passwords. It is intended for personal use 
and is not recommended for generating passwords for highly sensitive accounts.
 
## License
None.
