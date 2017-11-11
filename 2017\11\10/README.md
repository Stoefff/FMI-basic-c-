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

## Check enum and typedef

## rand

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
