# Structures in the code && loops exercise

## Literals
### Hard-coded raw value
### Examples:
    4; 3;

## Operators
### Combines two structures and does somethings with them
### Examples:
    + = if else for

## Statement
### Consists of the operation and the values with which the operators work. They are like command - the instruct the program to do operation with the values
### Examples:
    a = b + c;
    if( a > b ){
        ...
    } else {
        ...
    }

## Block
### Part of the code with is executed always consecutively
### Examples:
{  
    ...  
    expressions  
    ...  
    {  
        ...  
        expressions  
        ...  
    }  
    ...  
    expressions  
    ...  
}  

# Functions and procedures
## Basic syntax(layout)
``` cpp
<type> <name>(<arguments>){

}
```
#### We could have 2 functions with the same name and arguments but with different types and it works

## Define and declare
Define: when you set then function block

Declare: when you just show its existence without defining anything but the
type and arguments

## Check enumeration and typedef
## Rand
``` cpp
#include <random>
#include <ctime>

int main(){
    int x;
    //srand(10); // fucks it up again
    // x = rand(); fucks up the randomness
    srand(time(0));
    int x = rand() % 100 x 2;
}
```
