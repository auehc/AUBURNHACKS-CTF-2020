# rev_challenges

## rev1

Hidden Flag

Simple C program that only prints a portion of the flag when used.
Users are expected to open the binary in a disassembler and find the other portions of the flag.
By default the strings utility only shows strings of a certain length.
We made sure to make the flag portions smaller than that length so users could not simply just run strings.

## rev2

Easy crackme - Hard Coded Strings

C program that expects two inputs. If one input is right you get part of the flag, if both are right you get the whole flag.


## rev3

Medium Crackme - Assembly 

This challenge is a slightly complex assembly program. 
The main aim is for the user to get more used to seeing and working with assembly.
There are a multitude of if statements occurring in the program.
The first just check the number of arguments passed to the program.
If those checks succeed then it sends the users arguments to `alg`.
In there there is a simple calculation that multiplies the first user argument by the second user argument.
If the product is **1337** the flag will be provided to the user!

## rev4

Medium crackme - Vigenere

Basic compiled Java program.
Users are expected to use a Java Class decompiler as users are only provided with a class file and not the source code.
Once the code is decompiled it should become obvious how to solve as it is a simple XOR cipher.



## rev5

Advanced crackme - Keygen between values of **0 - 9**