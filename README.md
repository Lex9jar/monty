<h1 align="center">0x19. C - Stacks, Queues - LIFO, FIFO</h1><br><br><br>
<p align="center">
<img width="650" height="300" src="https://images.spiceworks.com/800x400/wp-content/uploads/2023/05/19111912/Shutterstock_1919441732.jpg">
</p>

------------

##The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

-------------

##Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
```
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
```

##COMPILATION & OUTPUT:
```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty
```

##USAGE:
```monty file
```

**FILES** | **OBJECTIVES**
[push] () | Pushes an element to the stack.
[pall] () | Prints all the values on the stack, starting from the top of the stack.
[pint] () | Prints the value at the top of the stack, followed by a new line.
[pop] () | Removes the top element of the stack.
[swap] () | Swaps the top two elements of the stack.
[add] () | Adds the top two elements of the stack.
[nop] () | Does nothing
[sub] () | Substract the top element of the stack from the second top element of the stack.
[div] () | Divides the second top element of the stack by the top element of the stack
[mul] () | Multiplies the second top element of the stack with the top element of the stack.
[mod] () | Computes the rest of the division of the second top element of the stack by the top element of the stack.
[pchar] () | Prints the char at the top of the stack, followed by a new line
[pstr] () | Prints the string starting at the top of the stack, followed by a new line.
[rotl] () | Rotates the stack to the top.
[totr] () | Rotates the stack to the bottom.
[stack] () | Sets the format of the data to a stack (LIFO).
[queue] () | Sets the format of the data to a queue (FIFO).
