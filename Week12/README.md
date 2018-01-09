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

### Tail recursion - going from the botom to the start
```c++
int sum(int n ){
    if(n == 0)
        return 0;
    return n + sum(n-1);
}
```

### Tree like - To be continued
