/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "decimalToBCD.h"


int main(){
    int number;
    unsigned char result[20];
    memset(result, '\0', sizeof(result));
    number = 8049;
    
    if (!FUNC_decimalToBCD(result, &number)){
        printf("error: wrong convert FUNC_decimalToBCD()\n");
    }
    else{
        /* two way to print OR the way you want :)) */
        printf("\n%s\n", result);
        for (int i = 0; i < 69; i++){
            printf("%c", result[i]);
        }
    }

    return 0;
}
