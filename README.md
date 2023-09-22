# 0x19. C - Stacks, Queues - LIFO, FIFO

## General
   - What do LIFO and FIFO mean
   - What is a stack, and when to use it
   - What is a queue, and when to use it
   - What are the common implementations of stacks and queues
   - What are the most common use cases of stacks and queues
   - What is the proper way to use global variables

## The Monty language
   - Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

#### Monty byte code files
     - Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
       ```bash
       username@ubuntu:~/monty$ cat -e bytecodes/000.m
       push 0$
       push 1$
       push 2$
         push 3$
                   pall    $
       push 4$
             push 5    $
       push    6        $
                       pall$
       ```

## Usage
   - compile all files:
     ```bash
        username@ubuntu:~/monty$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
     ```
   - Execution:
     ```bash
     username@ubuntu:~/monty$ ./monty bytecodes/00.m
     ```

## The monty program usage
   - Usage: monty file
     - where file is the path to the file containing Monty byte code
       - ex: **bytecodes/00.m**

### Opcodes
`monty` executes the following opcodes:

|  Opcode  |  Description                                   |
| -------- | -------------      |
| `push`   | Pushes an element to the stack |
| `pall`   | Prints all the values on the stack |
| `pint`   | Prints the value at the top of the stack |
| `pop`    | Removes the top element of the stack |
| `swap`   | Swaps the top two elements of the stack |
| `queue`  | Sets the format of the data to a queue (FIFO) |
| `stack`  | Sets the format of the data to a stack (LIFO) |
| `nop`    | Doesn't do anything                                                                                      |
| `add`    | Adds the top two elements of the stack                                                                   |
| `sub`    | Subtracts the top element of the stack from the second top element of the stack                          |
| `mul`    | Multiplies the second top element of the stack with the top element of the stack                         |
| `div`    | Divides the second top element of the stack by the top element of the stack                              |
| `mod`    | Computes the rest of the division of the second top element of the stack by the top element of the stack |
| `pchar`  | Prints the char at the top of the stack |
| `pstr`   | Prints the string starting at the top of the stack |
| `rotl`   | Rotates the stack to the top |
| `rotr`   | Rotates the stack to the bottom |

## Authors
* Wafae Chamour
* Mohammed Dakhamat

