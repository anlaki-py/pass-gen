passv2.5.cpp
==================

A command-line password generator that creates strong, secure passwords using C++.

Features
--------

* Generate random passwords with a specified length and character set
* Save generated passwords to a log file for future reference
* Exclude specific characters from the generated password
* Include only specific characters in the generated password
* Include uppercase and/or lowercase letters, digits, and/or symbols in the generated password
* Display version number and help message

Installation
------------

No installation is required - simply compile and run the `password_generator.cpp` file using a C++ compiler.

Usage
-----

To generate a password with the default character set and length, simply run the executable:
```
./password_generator
```
To generate a password with a specific length, use the `-l` or `--length` option:
```css
./password_generator -l 20
```
To generate a password with a specific character set, use the `-c` or `--characters` option:
```css
./password_generator -c "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_-+=[]{}|;:,.<>?"
```
To exclude specific characters from the generated password, use the `-x` or `--exclude` option:
```css
./password_generator -x "il1"
```
To include only specific characters in the generated password, use the `-i` or `--include` option:
```css
./password_generator -i "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"
```
To save the generated password to a log file, use the `-s` or `--save` option:
```
./password_generator -s
```
To display the version number and help message, use the `-v` or `--version` and `-h` or `--help` options, respectively:
```bash
./password_generator -v
./password_generator -h
```
Options
-------

| Option | Description |
| --- | --- |
| `-l` or `--length` | Specify the length of the generated password. |
| `-c` or `--characters` | Specify the character set to use for the generated password. |
| `-x` or `--exclude` | Exclude specific characters from the generated password. |
| `-i` or `--include` | Include only specific characters in the generated password. |
| `-s` or `--save` | Save the generated password to a log file. |
| `-v` or `--version` | Display the version number of the program. |
| `-h` or `--help` | Display the help message. |

Compiling
---------

To compile the `password_generator.cpp` file, use a C++ compiler such as g++:
```bash
g++ -o password_generator password_generator.cpp
```
This will create an executable file named `password_generator` that can be run to generate passwords.

Excluding Characters
-------------------

To exclude specific characters from the generated password, use the `-x` or `--exclude` option followed by the characters to exclude. For example, to exclude the characters "i" and "l":
```css
./password_generator -x "il"
```
Including Characters
-------------------

To include only specific characters in the generated password, use the `-i` or `--include` option followed by the characters to include. For example, to include only lowercase letters:
```css
./password_generator -i "abcdefghijklmnopqrstuvwxyz"
```
Log File
--------

To save the generated password to a log file, use the `-s` or `--save` option. By default, the log file is named `passwords.log` and is located in the same directory as the executable. To specify a different log file name and/or location, use the `-f` or `--file` option. For example, to save the generated password to a file named `my_passwords.log` in the `~/Documents` directory:
```bash
./password_generator -s -f "~/Documents/my_passwords.log"
```
Version
-------

The current version of the password generator program is 1.0.0. To display the version number, use the `-v` or `--version` option:
```bash
./password_generator -v
```
Help
----

To display the help message, use the `-h` or `--help` option:
```bash
./password_generator -h
```
Dependencies
------------

The password generator program requires the following libraries:

* C++ Standard Library
