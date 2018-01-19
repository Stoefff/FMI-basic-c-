### Passing arguments to main()

Visual studio has a mechanism with handles args

```c++
int main(int argc, char * argv[]){
    for(int i = 0; i < argc; ++i){
        std::cout << i << ": " << argv[i] << "\n";
    }

}
```

### 2D arrays of string handling
This is a static 2D array which e should be in the form of square or rectangle
If a value is exceed]ing the limit the compiler swears us
If the 2 offsets are not set the compilers swears us for the same reason
```c++
char words[6][4] = {
    "hellooooo",
    "world",
    "",
    "ok";
}
```

So how the OS handles argv and argc
With buffers in order to allocate argv dynamic to save memory
```c++

char buffer[1000]
size_t length;
char * anotherInput[argc];

for (int i = 0; i < 10; ++i){
    std::cin.getline(buffer, 1000);
    length - strlen(buffer);

    anotherInput[i] = new char[length + 1];
    strcpy(anotherInput[i], buffer);
}

for(int i = 0; i < 10; ++i)
    delete[] anotherInput[i];
```
### For HW3 Task3A

Input buffer can be static
Decompressed should be dynamic using 2 functions
1. Should count length recursivly to the next number or at the end '\0'
2. One which decompresses

```c++
    getlength(char * str){
        if(str == NULL || *str == '\0')
            return 0;
        else if(ifAlpha(*str))
            return 1 + getlength(str + 1);
        else if(isDigit(*str))


    }
```

Recursion can be tree like example:

ABC10(10(10(XYZ)))FGH
    ------------- ---
The one branch^    ^The second branch

Problem is handling how much should the size of the dym array ???

We could use function which takes numbers form a string

Another good way is starting from the deepest string and expanding from
inside to outside. This is done by counting the deepest bracket "(" but
this can be tricky because of the branches of dept which I think could be
solved again with tree recursion

### Passing function to function
```c++
void *(foo)();

int sum(int x, int y){
    return x + y;
}

int main(){
    int(*fptr)(int, int); // poiter to funcs with args (int, int);

    fptr = sum; // Compilers skips &sum;
}
```
In order to skip the shitty syntax we use typedef
```c++
int add(int x , int y){
    return x + y;
}
int sub(int x, int y){
    return x - y;
}

typedef int(* fptrOperation)(int, int); // This skip predefining all the Operations

fptrOperation selectOpeartion(char opCode){
    //here selects with what functions to calculate
}

int eval(char opCode, int lhs, int rhs){
    fptrOperation = operation  = selectedOperation(opCode);
    if(operation = nullptr){
        std::cot << "Invalid";
        return 0;
    }
    return operation(lhs, rts);
}
```

### Pipelines
Pipes are actually F(x) + G(y) + H(z) => A + H(z) => B
Check Vasi's repos
