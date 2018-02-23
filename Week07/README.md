## Visual Studio compiler vs G++
In Visual Studio you cant initialize array with size entered from the user  
In G++ you can do it but it is not good(could fuck up in various diff ways)  
**DON'T DO IT**

## 2D arrays
Watch out when passing by reference

## Simple sorting algorithms:  

### Bubble:  
> Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.  

```c++
void bubbleSort(int arr[], int n){
   int i, j;
   for (i = 0; i < n-1; i++)      

       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
```  

### Selection:  
> The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering > ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two > subarrays in a given array.  

``` c++
void selectionSort(int arr[], int n){
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
```  

### Insertion Sort:  
> Insertion sort is a simple sorting algorithm that works the way we sort playing cards in our hands

``` c++
void insertionSort(int *arr, int size){
    for(int i; i < size; i++){
        for(int j = 1; j > 0 && arr[j] < arr[j - 1]; j--){
            std::swap(arr[j], arr[j -1]);
        }
    }
}
```
