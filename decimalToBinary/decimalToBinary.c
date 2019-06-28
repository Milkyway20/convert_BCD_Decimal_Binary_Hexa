#include <stdio.h>
#include <math.h>
#include "decimalToBinary.h"

_Bool swap(unsigned char *arr, int *lenArr){
    unsigned char temp = 0;
    if (*lenArr < 1){
        return FALSE;
    }
    else if(*lenArr == 1){
        return TRUE;    
    }
    else{
        for (int i = 0; i < *lenArr/2; i++){
            temp = arr[i];
            arr[i] = arr[*lenArr-i-1];
            arr[*lenArr-i-1] = temp;
        }
    }
    return TRUE;
}

/* the integer >= 0 */
_Bool decimalToBinary(unsigned char *pDesti, int *pSource, int *lenDesti){
    int temp;
    temp = *pSource;
    *lenDesti = 0;
    if (temp < 0){
        printf("\nerror: input < 0\n");
        return FALSE;
    }
    
    /* convert */
    do{
        if (*pSource/BINARY == 0){
            *pDesti = 1;
            *lenDesti += 1;
            break;
        }
        else{
            *pDesti = *pSource%BINARY;
            *pSource /= BINARY;
            *lenDesti += 1;
            pDesti++;
        }
    }while(TRUE);

    pDesti = pDesti - (unsigned char)*lenDesti + 1;

    /* swaps position */
    if (!swap(pDesti, lenDesti)){
        printf("\nerror: swap was wrong\n");
        return FALSE;
    }
    
    return TRUE;
}
