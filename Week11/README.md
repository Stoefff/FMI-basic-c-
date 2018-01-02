## Strings

### Difference between " " and ' '
    "" - have a \0 at the end and '' does not so its just one symbol

### String pooling and differences between char[] and char*
```c++
char buffer[] = "Hello World!";
char* p = "Hello World!";
char* p1 = "Hello World!";
//Because both pointer lead to the same literal so it could also lead to
// both pointer pointing to the same memory
// ^^^ This is called string polling ^^^

//The alternative good practice
const char* p2 = "Hello World";
const char* p3 = "Hello World";

buffer[0] = 'h' ; // Good to do
p[0] = 'h'; // Bad
```
```c++
int arr[10] = {};

int* p = arr;

p[9] = 42; // Here compilers are optimized to iterate like *(arr + i)
// where i is the 9 * sizeof the type which is the array (Array arithmetic)
// no need to use *p because of this ^^ syntax
*p = 42; // Changed the first element of the array
```

### Passing arrays
```c++
void func(int * p, size_t size){
    for(size_t i = 0; i < size; i++){
        std::cout << p[i] << std::endl;
    }
}

int main(){
    int arr[10] = {};

    func(arr, 10);
}
```

### strlen()
```c++
int MyStrlen(const char* str){
    const char* p = str;
    while(*p != '\0')
        p++;
    return (p - str)
}
int main(){
    char buffer[] = "dank memes"
    std::cout << Mystrlen(buffer) << "\n";

    buffer[4] = '\0'; //Cutting the string like a pro

    std::cout
        << buffer
        << " -> "
        << Mystrlen(buffer)
        << "\n";

}
```

### std::cin vs std::getline()
std::cin - searches to space not \0 !!!!!!!!!!!!!!!!!! also could fuck up memory
getline() is DANGEROUS !!! -
!!! getline could have a parameter which say which symbol is searched for ending
!!! the default is \0 . Use this for the homework
```c++
char name[19];
std::cin >> name;
std::getline();

```

### std::cerr

### passing strings to functions
```c++
void print(const char * str); //valid way
char * name="Plamen"; //Literal, const
char name[]="Plamen"; //Coulde be changed;
```

### strlen
This uses a copy of the pointer so we wont lose pointer to the start in main
```c++
unsigned int myStrlen(const char * string){
    unsigned length = 0;
    while(string[length]){
        length++;
    }
    return length;
}
```
### strcpy();
### strcmp();
### strcat();
