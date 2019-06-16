#include <stdio.h>
#include <math.h>
#include "strHexaToDecimal.h"

int main()
{
    unsigned char arr[4] = "3f4d";
    int result = 0;
    
    if (!strHexaToDecimal(&result, arr, strlen(arr))){
        printf("\nerror: convert is falsed\n");
    }
    else{
        printf("%d", result);
    }

    return 0;
}
