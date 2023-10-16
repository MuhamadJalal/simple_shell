## Simple Shell

### Description

The Simple Shell is a simple UNIX command interpreter written entirely in C. The
program runs based on bash commands obtained from the input stream by the user.
Any text seperated by a single space is considered to be an argument. The
respective command typed by the user is then executed as if in a UNIX shell.

### Requirements

* Allowed editors: vi, vim, or emacs
* All files were compiled on Ubuntu 14.04 LTS
* Programs and functions were compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* All files should end with a new line
* Code should use the Betty style. It is checked using betty-style.pl and betty-doc.pl
* No more than 5 functions per file
* All header files should be include guarded
* System calls are only used when needed

### Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

### List of Allowed Functions & System Calls

[Referral](https://docs.google.com/document/d/1Oe7n8L_KbpcVRqcx9l9z3ROJvtI6GVI01ffM8OafCt8/edit)

* access (check real user's permissions for a file)
* execve (execute program)
* exit (cause normal process termination)
* fflush (flush a stream)
* fork (create a child process)
* free (free dynamic memory)
* getline (delimited string input)
* isatty (test whether a file descriptor refers to a terminal)
* malloc (allocate memory)
* perror (print a system error message)
* read (read from a file descriptor)
* strtok (extract tokens from strings)
* wait (wait for process to change state)
* write (write to a file descriptor)

### Usage

The shell works like this in interactive mode:

```bash
$ ./hsh
$ /bin/ls
hsh shell.c path.c README.md
```

```bash
$ exit
$
```



### Built-Ins

The simple shell has support for the following built-in commands:

| Command | Definition            |
| ------------------- | ----------
| env     | Prints the environment
| exit    | Exits the shell



### Author

[Muhamad Jalal](https://github.com/MuhamadJalal)
