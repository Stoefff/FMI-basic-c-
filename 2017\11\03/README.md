## This was the exam
We have a given number: 10010101

Want to get 1(2) bit value
And we want to set the 3(4) bit

``` c++
unsigned mask = 1;
bool value = number & (mask << getter);
number = number | (value << setter);
```

But this is incorrect, beacuse in certain cases it wont work
We should write it with to if cases
Or maybe it would be very fast to write it just with bin ops
