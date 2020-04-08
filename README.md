![Holberton school]
(https://ph-files.imgix.net/75aa6247-480b-460b-b31b-e1365169cd1b?auto=format)

# 0x16. C - Simple Shell

## Description
In this project we are creating our own simple UNIX command interpreter. The program must have the exact same output as sh (/bin/sh) as well as the exact same error output. The only difference is when you print an error, the name of the program must be equivalent to your argv[0].

## Usage
- Enter custom shell by typing "./hsh". You should be prompted with a ($).
- Type a command of your liking and press "Enter".
- Appropriate output will appear.
- Prompt reappears and awaits your next command.
- Exit shell by typing "exit"

## Installation
### Clone the repository. Compile the ".c" files. Run executable.
```
$ git clone https://github.com...
```

## Compilation
### Enter the following command to compile:
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

## Example
### Interactive Mode
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

### non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

| ### Files|
| ### File| ### Description|
| shell.c| executes the shell|
| shell.h| header|
| man_1_simple_shell| man page|
| | |
| | |
| | |
| | |
| | |
| | |
| | |
| | |
| | |

## Project Requirements
- All your files will be compiled on Ubuntu 14.04 LTS
- Your C programs and functions will be compiled with gcc 4.8.4 using th- e flags -Wall -Werror -Wextra and -pedantic
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-s- tyle.pl and betty-doc.pl
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to

## Tasks
### 0. README, man, AUTHORS
- Write a (README)[./README.md]
- Write a (man)[./man_1_simple_shell] for your shell.
- You should have an (AUTHORS)[./AUTHORS] file at the root of your repository, listing all individuals having contributed content to the repository.

### 1. Betty would be proud
- Write a beautiful code that passes the Betty checks

### 2. Simple shell 0.1
- Write a UNIX command line interpreter.
- Your Shell should:
  - Display a prompt and wait for the user to type a command. A command	    line always ends with a new line.
  - The prompt is displayed again each time a command has been executed.
  - The command lines are simple, no semicolons, no pipes, no redirectio    ns or any other advanced features.
  - The command lines are made only of one word. No arguments will be pa    ssed to programs.
  - If an executable cannot be found, print an error message and display    the prompt again.
  - Handle errors.
  - You have to handle the "end of file" condition (Ctrl+D)

### 3. Simple shell 0.2
- Handle command lines with arguments

### 4. Simple shell 0.3
- Handle the PATH

### 5. Simple shell 0.4
- Implement the exit built-in, that exits the shell
- Usage: exit
- You dont have to handle any argument to the built-in exit

### 6. Simple shell 1.0
- Implement the env built-in, that prints the current environment

### 7. What happens when you type ls -l in the shell
- Blog:
  - LinkedIn

## Authors
- Marisol Ramirez Henao
- David Alejandro Hincapie
