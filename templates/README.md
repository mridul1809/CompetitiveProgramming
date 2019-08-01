# Matrix Template

Class for Matrix manipulation. Several regularly used operators have been overloaded providing important functionalities.

Operators overloaded :
"+" , "+=" , "*" , "*=" , "-" (unary & binary), "-=" ,"^" , "^="(power using binary exponentiation)

Utility Operators :
overloaded ostream "<<" to print the matrix , "[]" to random access using object directly


Examples on how to use these operators have been provided along with the code.

## Notes
To use operations with modulo operator , you need to define a macro "mod" with required value.

# Trie Template

Class for Trie data structure. Now the regular implementation of trie is via pointers , but I have done it in form of a vector! 
In pointer form implementation every node of trie is a new allocation in memory , here it comes at some index in vector!
Instead of storing pointer to that block , index of that node is stored in next[ ] array!

Functions added : Insert string , check if string exists as a prefix , check is string exists as it is!

Examples on how to use the functions have been provided along with the code. 