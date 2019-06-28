#include <stdio.h>
#include <math.h>
#include "decimalToBinary.h"

int main()
{
    unsigned char arr[100];
    int a = 100;
    int b = 0;
    decimalToBinary(arr, &a, &b);
    
    for (int i = 0; i < b; i++){
        printf("%d", arr[i]);
    }

    return 0;
}
