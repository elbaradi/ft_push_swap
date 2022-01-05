Note: _This was my eigth 42 project, completed August 2021. With this project I discovered how much I enjoy algorithms. I wrote a highly efficient custom stack-sorting algorithm, of which I'm still very proud of! It sorts a stack of 500 numbers in 4,000 instructions (over 25% less instructions than what was required for the highest grade). For fun, we fed the algorithm 100,000 integers, which it sorted in less twenty seconds and 1,600,000 instructions (four minutes faster than the school's checker)._

_This README was written by the lovely [Lotte Hageman](https://github.com/RascalCalmind), it was copied and adjusted with her permission; it perfectly describes the project._

[![Logo](https://github.com/qingqingqingli/readme_images/blob/master/codam_logo_1.png)](https://github.com/qingqingqingli/cub3d)


# ft_push_swap
This repository contains two programs. One sorts a list of integers from the standard input with some constraints on how you are allowed to sort them. The other checks if a provided sorting solution is correct. The purpose of the project is to learn more about sorting algorithms and their characteristics. And the computational complexity of algorithms.

## Compiling
Run ```make``` to compile the ```push_swap``` main sorting algorithm. Run ```make checker``` to compile the checker.

## Challenge
#### Push_swap:
The goal is to sort the list of integers using only 2 stacks: stack a and stack b. 

Beside that restriction you will only be allowed to use these 11 operations:
* ```sa``` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
* ```sb``` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
* ```ss``` : ```sa``` and ```sb``` at the same time.
* ```pa``` : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* ```pb``` : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
* ```ra``` : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
* ```rb``` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
* ```rr``` : ```ra``` and ```rb``` at the same time.
* ```rra``` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
* ```rrb``` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
* ```rrr``` : ```rra``` and ```rrb``` at the same time.

#### Checker:
The goal is to check if the list is sorted or not, allowing the user to give a list of integers as parameter and then asking for operations to perform before evaluating the list.
Checker will give a OK if the list is sorted and a KO if it's not.
You can stop the program by pressing ENTER or CTRL+D.

## Usage
After creating the executable files, ```checker``` and ```push_swap```, they can be executed by giving them a list of integers as parameter e.g.:

```./push_swap 0 5 1 2 -4```

In this case, the output looks like shown below. 

```
-----------------------------------------------
|	0		|
|	5		|
|	1		|
|	2		|
|	-4		|
|			|
-----------------------------------------------
|  stack a		|  stack b
-----------------------------------------------

pb
rra
pb
sb
rra
rra
pa
pa

Amount of calculations: 8
```

It will visualize what the beginning of the stacks looks like, the steps it will do to sort the list and the amount of calculations/steps used to sort the list.


```./checker 0 3 1```

In this case if we press ENTER or CTRL+D right away, the output looks like shown below. 

```
-----------------------------------------------
|	0		|
|	3		|
|	1		|
|			|
-----------------------------------------------
|  stack a		|  stack b
-----------------------------------------------

KO
```

If we were to use some operations, you will call the program and afterwards type an operation followed by an ENTER to perform said operation.

```
./checker 0 3 1 2
pb
sa
pa
```

## Challenge
Allowed functions for the mandatory part are ```exit```, ```write```, ```read```, ```malloc``` and ```free```.
The challenge is to try to get the least amount of operations to sort a list of certain amounts of values. In the end the project was tested on how the algorithm for ```push_swap``` sorts lists of 3, 5, 100 and 500 random integer values and with how many operations.
