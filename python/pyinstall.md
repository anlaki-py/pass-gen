## [YouTube tutorial](https://youtu.be/bqNvkAfTvIc?si=sGms_E07rRouZSJq)

Let's go over how you can use PyInstaller to create standalone executables from your Python code. PyInstaller can be used to package Python applications on both Windows (to create .exe files) and Linux.

Firstly, you'll need to install PyInstaller. You can do this using pip, the Python package installer. 

```bash
pip install pyinstaller
```

After you've installed PyInstaller, you can use it to create an executable. Here's a basic usage example:

```bash
pyinstaller your_script.py
```

This command will create a `dist/` folder in the same directory as your script, which contains the executable file. If you're on Windows, the file will have a .exe extension. On Linux, there will be no extension.

If you want to package your application into a single file, you can use the --onefile option:

```bash
pyinstaller --onefile your_script.py
```

This will create a single executable file in the `dist/` folder.

By default, the console window is shown when running the program. If you're creating a GUI application and want to hide the console, you can use the --noconsole option (Windows only):

```bash
pyinstaller --onefile --noconsole your_script.py
```

Keep in mind that PyInstaller packages everything needed to run your script, including the Python interpreter and any libraries your script uses. As a result, the output file can be quite large.

Also, be aware that while PyInstaller makes your script into a standalone executable, it doesn't truly "compile" your Python in the same way a C++ compiler would. The Python code is still interpreted, and the original script can be extracted and viewed. If you need to protect the source code of your Python script, you'll need to use additional tools or methods to obfuscate the code.

# Note
The output of PyInstaller is specific to the active operating system and the active version of Python. This means that to prepare a distribution for:

- a different OS
- a different version of Python
- a 32-bit or 64-bit OS

you run PyInstaller on that OS, under that version of Python. The Python interpreter that executes PyInstaller is part of the bundle, and it is specific to the OS and the word size.

For more detailed instructions and options, you can refer to the [PyInstaller Documentation](https://www.pyinstaller.org/).