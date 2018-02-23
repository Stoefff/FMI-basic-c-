## How to compare 2 float numbers
Its done with a constant of float type EPS = 0.0001 which gives the accuracy  
```c++
const float EPS = 0.001;
a = 5.373434;
b = 5.378767;
if (abs(a-b) < EPS){
    std::cout << "True"
} else {
    std::cout << "Fasle"
}
```
Event when comparing with ZERO we should use the the EPSILON method  
**ANY** float var has random digits at the end  

## Memory
### Automatic or Stack
Stack frame - dependent of the current scopes  
Formal(name) and real(value) types vars
There are stack pointers and base/frame pointers

### Static
Not dependent on any scopes
```c++
const int SIZE = 64
int main(){
    ...
    ...
    ...
}
```
Maybe Global vars?

### Dynamic
Passing by:
* Value
* Reference

Pointers
```c++
int a = 5;
int b = 10;
int * p;
p = &a;
*p = 20 // Sets the value

std::cout << &p; //Prints the address of the pointer itself

int* p = NULL; // Good practice or bad practice ?
```
Heaps
```c++
int* arr = new int[10];
```
