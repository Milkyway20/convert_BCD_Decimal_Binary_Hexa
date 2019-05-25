/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>
#include "BCDToDecimal.h"

const int BCD = 4;
const int BCD_MAX = 9;
const float BINARY = 2.0;
const float DECIMAL = 10.0;

/* FUNC_bcdToDecima */
int FUNC_bcdToDecima(int *pDesti, unsigned char *pSource, int lenSour){
    int lenDesti;
    int value;
    if (lenSour%BCD || lenSour <= 0){
        printf("error: lenSour\n");
        return FALSE;
    }
    lenDesti = (int)lenSour/BCD;
    for (int i = 1; i <= lenDesti; i++){
        value = 0;
        for (int j = 1; j <= BCD; j++){
            value += (int)(*pSource)*pow(BINARY, (float)(BCD-j));
            pSource++;
        }
        if (value > BCD_MAX){
            printf("error: *pSource - have a BCD'value > 9\n");
            return FALSE;
        }
        *pDesti += (int)value*pow(DECIMAL, (float)(lenDesti-i));
    }
    return TRUE;
}

/* FUNC_StrBCDToDecima */
int FUNC_StrBCDToDecima(int *pDesti, unsigned char *pSource, int lenSour){
    unsigned char source[lenSour];
    for (int i = 0; i < lenSour; i++){
        if (*pSource == '0'){
            source[i] = 0;
        }
        else if(*pSource == '1'){
            source[i] = 1;
        }
        else{
            printf("error: *pSource - have a element in BCD string neither 1 nor 0\n");
            return FALSE;
        }
        pSource++;
    }
    
    if (!FUNC_bcdToDecima(pDesti, &source[0], lenSour)){
        printf("\nerror: FUNC_bcdToDecima()\n");
        return FALSE;
    }
    return TRUE;
}
