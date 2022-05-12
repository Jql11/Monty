# Monty - it's not quite Python :snake:
![The original Monty](https://github.com/Jql11/monty/blob/main/monty.png)
A C interpreter for Monty ByteCode files as part of the [Holberton School](https://holbertonschool.com.au/) Foundations curriculum for Low-Level Programming.

## Usage :clapper:
To use Monty, clone the repo and run the following (where `filename.m` is
replaced with the correct bytecode file:
```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty
$ ./monty filename.m
```

### Example
```
$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
$ ./monty bytecodes/00.m
3
2
1
$
```

### Coding Style :technologist:
All files are written in C programming language and follows the
[Betty coding style](https://github.com/holbertonschool/Betty/wiki).

## Description :speech_balloon:

### File Descriptions :floppy_disk:
- **bytecodes:** Monty bytecode files
- **char_str.c:** Functions for printing strings
- **dict.c:** Dictionary of functions
- **main.c:** Driver to run the program
- **math_ops.c:** Functions for mathematical operations
- **monty**: Monty files
- **monty.h**: Header file containing structs and prototypes
- **pop_free_swap.c:** Functions to manipulate the stack
- **push_pall.c:** Functions to print to stdout
- **rot.c:** Functions to rotate the stack

## Operation Codes :computer:
The following operation codes can be used:
| Opcode | Description |
| -------| ----------- |
| push | pushes an element to the stack |
| pall | prints all the values on the stack, starting from the top |
| pint | prints the value at the top of the stack |
| pop | removes the top element of the stack |
| swap | swaps the top 2 elements of the stack |
| nop | doesn't do anything
| add | adds the top 2 elements of the stack |
| sub | subtracts the top element from the second element on the stack |
| div | divides the second element from the top element on the stack |
| mul | multiples the top 2 elements of the stack |
| mod | divides the second element from the top element and returns remainder |
| # | ignores lines starting with # |
| pchar | converts a number to the equivalent ascii character and prints it |
| pstr | converts numbers to the equivalent ascii and prints the string |
| rotl | pushes the first element of the stack to the bottom |
| rotr | pushes the last element of the stack to the top |

## Authors :pencil2:
- Jacqueline Lu [[Jql11](https://github.com/Jql11)]
- Farah McCurdy [[farahmc](https://github.com/farahmc)]
