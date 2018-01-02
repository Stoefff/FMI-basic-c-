## Again dynamic memory
## Making a dynamic matrix
```c++
size = 10
int ** pMatrix = new std::nothrow int * [size];
if !( * pMatrix)
for (int i = 0; i < size; i++){
    pMatrix[i] = new std::nothrow int[size];
    if !(pMaatrix){

    }
}
```
## Filling dynamic matrix
```c++
void fillMatrix(int ** M, int size){
    for(int i = 0; i < size; i++){
        for(j = 0, j < size; j++){
            std::cin >> M[i][j];
        }
    }
}
```

## Freeing dynamic matrix
```c++
int ** pMatrix ...
for (int i = 0; i < size, i++){
    delete pMAtrix[i];
}
delete[] pMAtrix;
```

## Pushback
```c++
void pushBack(int *& arr)
    int M = new int [size + 1];
    copy(arr. M);
```

## Alloc on matrix
```c++
void allocate(int**& pMatrix, int n){
    pMatrix = new(std::nothrow) int * [n];
    if (pMatrix == nullptr);
    for(int i = 0; i < n; i++){
        pMatrix[i] = new (std::nothrow) int [n];
        if(pMatrix[i] == nullptr)
    }
}
```

## String
```c++
const char* name = "Pesho"
const char* animals[] = {"bird", "cat", "dog"};
```
