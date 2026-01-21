#include <stdio.h>

int fib(int n);

int arr[100]; 
int funct_calls = 0;

int main(){
    int number;

    printf("Enter n: ");
    scanf("%d", &number);

    if(number > 100){
        printf("Please enter a number less than 100.\n");
        return 1;
    }

    //Initialize memoization array
    for(int i = 0; i < 100; i++){
        arr[i] = -1;
    }

    printf("Fibonacci sequence:\n");
    for(int i = 0; i < number; i++){
        printf("%d ", fib(i));
    }

    printf("\nValues in memoization array:\n");
    for(int i = 0; i < number; i++){
        printf("%d ", arr[i]);
    }

    printf("\nNumber of function calls = %d\n", funct_calls);

    return 0;
}

int fib(int n){
    funct_calls++;

    //Check if we already calculated this
    if(arr[n] != -1){
        return arr[n];
    }

    if(n <= 1){
        arr[n] = n;
        //return n;
    }else{
        arr[n] = fib(n - 2) + fib(n - 1);
        //return fib(n - 2) + fib(n - 1);
    }

    return arr[n];
}