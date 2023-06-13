Description of solution A
===========
The opening and closing brackets are stored in the bracket_open and bracket_close arrays. 
The stack is initially empty.

The OK variable is used to exit the outer loop when an error is encountered. 
It becomes 0 if a bracket of a different type is found or the stack is empty. 

We write the opening bracket onto the stack and remove the top bracket from the stack if we find a bracket of the same type, but closing. 
If by the end of the program the stack is empty, it means that the parentheses are placed correctly.