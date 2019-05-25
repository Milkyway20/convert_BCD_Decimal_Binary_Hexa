/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "decimalToBCD.h"

const int DECIMAL_MAX = 99;

int FUNC_convert(unsigned char *desti, unsigned char *source){
    if (*source > 9 || *source < 0){
        printf("error: wrong *desti of FUNC_convert()\n");
        return FALSE;
    }
    switch(*source){
        case 0: strcat(desti, "0000"); break;
        case 1: strcat(desti, "0001"); break;
        case 2: strcat(desti, "0010"); break;
        case 3: strcat(desti, "0011"); break;
        case 4: strcat(desti, "0100"); break;
        case 5: strcat(desti, "0101"); break;
        case 6: strcat(desti, "0110"); break;
        case 7: strcat(desti, "0111"); break;
        case 8: strcat(desti, "1000"); break;
        case 9: strcat(desti, "1001"); break;
        default:
            printf("error: wrong *source of FUNC_convert()\n");
            return FALSE;
    }
    return TRUE;
}

/* FUNC_decimalToBCD() */
int FUNC_decimalToBCD(unsigned char *desti, int *source){
    int lenSource;
    int temp;
    unsigned char arrSource[DECIMAL_MAX];
    memset(arrSource, '\0', sizeof(arrSource));
    
    lenSource = 0;
    temp = *source;
    
    /* find lenSource */
    do{
        *source = *source/10;
        lenSource += 1;
    }while(*source > 0);
    
    /* save source to arrSource[] */
    for (int i = 0; i < lenSource; i++){
        arrSource[i] = (unsigned char)(1.0*temp/pow(10.0, 1.0*(lenSource-i-1)));
        temp = temp%(int)pow(10.0, 1.0*(lenSource-i-1));
    }
    
    /* after convert, result saved at desti */
    for (int i = 0; i < lenSource; i++){
        if (!FUNC_convert(desti, &arrSource[i])){
            printf("error: FUNC_convert() had error\n");
            return FALSE;
        }
    }
    
    return TRUE;
}
