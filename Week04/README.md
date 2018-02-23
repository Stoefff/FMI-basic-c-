## This was the exam
We have a given number: 10010101

We want to get 1(2) bit value and set it to the 3(4) bit

``` c++
unsigned mask = 1;
bool value = number & (mask << getter);
number = number | (value << setter);
```

But this is incorrect, because in certain cases it wont work  
We should write it with two if cases or just with bin operations
