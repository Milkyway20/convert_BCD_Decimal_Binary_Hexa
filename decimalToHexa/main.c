#include <stdio.h>
#include <math.h>
#include "decimalToHexa.h"

int main()
{
    unsigned char arr[100];
    int a = 100;
    int b = 0;
    decimalToHexa(arr, &a, &b);
    
    for (int i = 0; i < b; i++){
        printf("%c", arr[i]);
    }

    return 0;
}
