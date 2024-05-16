To run a C++ program on a Linux system like Ubuntu, you can follow these steps:

1. **Install the GCC compiler**: Before you can compile and run a C++ program, you need to have the GNU Compiler Collection (GCC) installed on your system. You can install it using this command:
```
sudo apt update
sudo apt install build-essential
```
The `build-essential` package includes a lot of tools necessary for compiling software, including `gcc`.

2. **Create your C++ file**: You can use any text editor to write your C++ code. If you don't have one, you can install one like `nano` using `sudo apt install nano`.

3. **Compile your C++ file**: To compile a C++ file, navigate to the directory containing your .cpp file using the `cd` command. Then use the `g++` command followed by the name of your .cpp file to compile it. For example, if your file is named `program.cpp`, you would type:
```
g++ program.cpp -o program
```
The `-o program` option specifies the output file name. If you don't use `-o`, the output file will be named `a.out` by default.

4. **Run your program**: After your C++ file has been compiled, you can run it by typing `./` followed by the name of the output file. For example:
```
./program
```