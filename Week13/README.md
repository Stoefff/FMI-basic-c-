## String details
### ASCII table and chars:
Actually the max char is 127  

When comparing chars with different encoding one underwater rock could be the
encoding such as different types of char. This could be solved when casting
to UNSIGNED CHAR  

### strcmp() is one big underwater rock
```c++
int strcomp(const char *str1, const char str2){
    unsigned char c1, c2;
    int diff;

    do{
        c1 = (unsinged int) * str1++;
        c2 = (unsigned int) * str2++;

        diff = c1 - c2;
    } while ((diff == 0) && (c1 != '\0'));

    return diff;

}
```

### Building strings with strcat() and strcpy()
So in order to sum strings into a buffer we first use strcpy() in order to not
FUCK UP the \0. If we only use strcat(), the \0 is nowhere to be found  

Other problem: if we go after the limit of the static char[] the program will be
executed but in production we program will crash. What will happen:  
The string will change memory in the stack which is not its belonging for
example: other variables form main() so the program will die like a hero.

This can be easily solved by the buffer which handles the input  
In order no to write if which checks the length of this buffer, there is a
strcat_s() and strcpy_s() which have arguments which is the max length of buffer
that can be reached.  
**TODO: CHECK DOCUMENTATION**

### Stack canary
Watching if such ^ strings fucks up the stack and stops it if does so
There is another way of defending the stack  

### CPP lib for memory leaks detection :

## 2D arrays details:
Actually using arr[][] is quite slower than using pointer arithmetics because
is likely that the memory of 2D array in not ordered in the memory

**TODO: There are some spicy notes on the topic in Vasi's repo - `CHECK` !!!**    
**Check the fuck up recursion task in the repo**
