/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>
#include "BCDToDecimal.h"

unsigned char arr[20] = {1,0,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0};
unsigned char arr1[20] = "10010010100010000100";


int main()
{
    int decima = 0;
    int decima1 = 0;
    /* convert arr[0] of BCD to Decimal */
    if (!FUNC_bcdToDecima(&decima, &arr[0], 20)){
        printf("error: ... \n");
    }
    else{
        printf("%d\n", decima);
    }
    
    /* convert arr1[4]-arr1[11] of BCD to Decimal */
    if (!FUNC_StrBCDToDecima(&decima1, &arr1[4], 8)){
        printf("error: ... \n");
    }
    else{
        printf("%d\n", decima1);
    }

    return 0;
}
