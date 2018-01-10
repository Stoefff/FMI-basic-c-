## Recursion

### Vasi went must nuts about Fractals

### Recursion in coding xD

```c++
void printf(int iter){
    if(iter < 10){
        cout >> "Hello World";
        iter++;
        printf(iter)
    }
}

int main(){
    int iter = 0;
    printf(iter);

    return 0;
}
```

### Types of recursion

#### Linear - going form start to bottom
```c++
int sum(int number, int result = 0){ // if result is not passed, default is 0 !!
    if(number <= 0)
        return result;
    sum(number-1, result + number); //f here "return" is not written it will be
    // executable and compilable thanks to some processor registries
}
```

### Tail recursion - going from the bottom to the start
```c++
int sum(int n ){
    if(n == 0)
        return 0;
    return n + sum(n-1);
}
```

### Tree like - To be continued

### Spectre and  meltdown and some low level shit

Semerjiev is explaining about instruction sets and registries.
He showed us how the "if" operator makes goto in the registries memory.
TODO: Check how the "if" tree of the code generates registry address to the the
goto jumps when "if" is executed or just how the instruction set is generated
with registry pointer to the memory

So in modern chips not every instruction is taken from the instruction set
which is maybe in L1 cache ?????. So to prevent this the chip loads whole blocks
of instruction from the cache to the registries

Chips have 2 ways of optimizing which:
RIGHT/WRONG checking - Speculation execution
Parallelism

Mechanism of Meltdown:
Simple way of explaining: takes uncleared cache data which is actually
unprotected

Spectre even could inject code

Speculation control Script -

# How the functions work in the stack by Semerjiev:

Exactly after the stack pointer in the begging the arguments are written
After that there is the functions and their local variables
So when functions in order to go back to the starting pointer before the
function call the pointer goes back with help of a base pointer or frame pointer
which helps to navigate back before the function call.

This thing we learned in OS back in ELSYS - base pointer is the start of the
stack in this case the function and navigates with stack pointer  
