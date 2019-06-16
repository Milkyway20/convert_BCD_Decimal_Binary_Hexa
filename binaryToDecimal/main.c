#include <stdio.h>
#include <math.h>
#include "strBinaryToDecimal.h"

int main()
{
    unsigned char arr[10] = "1001101001";
    unsigned char arr1[4] = "1010";
    int result = 0;
    
    if (!strBinaryToDecimal(&result, arr1, 4)){
        printf("\nerror: convert is falsed\n");
    }
    else{
        printf("%d", result);
    }

    return 0;
}
