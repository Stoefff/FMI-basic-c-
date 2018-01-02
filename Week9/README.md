## Algos in arrays

Doc. Semergiev talked about some problems from the 1-st semester exam like:  
  * How to delete from array
  * Advanced indexing for moving in the array (like that one i used in the exam)
  * Advanced moving in 2D arrays for completing task 2B in HW2  

N.B. : Write a boolean func that compares wherever 2 colors are close(CheckWiki for algos)

## Memory continue
 * Automatic
 * Static
    * Outside, right before the stack
    * All var with "static" in front of them
 * Dynamic
    * Pointer and const
        const int * bite = 1024; - variable address, cosnt value
        int const * bite = 1024; - variable address, cosnt value
        int * const bite = 1024; - cosnt addrees, variable value
    * Reference (logicheski psevdonim)
        * No null pointer cust const
        * like const pointer int & ref <=> int * const ref
        ``` c++
        void swap(int & p, int & q){
            int temp = p;
            p = q;
            q = temp;
        }
        int main(){
            int a = 5, b = 6;
            swap(a, b);
            std::cout << a << b;


        }
        ```
        **Main difference between pointer and references is that when passing
        pointers you should pass address pointing to the variables and
        when using reference is that the function takes the the address of the
        of the passed var with out pointer**
        * How arrays work
        ```c++
        arr[5] = * (arr + 5) // this shouldn't be * (arr + 5*(sizeof(int)))
        ```
        This shouldn't be * (arr + 5*(sizeof(int)))
        because the compile does this for us by detecting the type of arr
        * How to iterate through array with pointer
        ```c++
        int main(){
            int arr[] = {1, 2, 3};
            int size = 3;
            int * p = arr;
            for(int i = 0; i < size; i++) {
                std::cout << * p;
                p++;
            }
        }
        ```
        * Dynamic arrys
        ```c++
            int * p = new (std::nothrow) int[64];
            if(!p) {std::cout << "Stop the Chrome"}
            std::cout << *p;
                p++;
            delete [] p; // Iteration is done automatically we should just write this
        ```
        ** **
