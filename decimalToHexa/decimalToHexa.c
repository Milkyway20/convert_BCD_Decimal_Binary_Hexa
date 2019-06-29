#include <stdio.h>
#include <math.h>
#include "decimalToHexa.h"

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
_Bool decimalToHexa(unsigned char *pDesti, int *pSource, int *lenDesti){
    int temp;
    temp = *pSource;
    *lenDesti = 0;
    if (temp < 0){
        return FALSE;
    }

    /* convert */
    do{
        if (*pSource/HEXA == 0){
            *pDesti = *pSource%HEXA;
            *lenDesti += 1;
            break;
        }
        else{
            *pDesti = *pSource%HEXA;
            *pSource /= HEXA;
            *lenDesti += 1;
            pDesti++;
        }
    }while(TRUE);

    pDesti = pDesti - (unsigned char)*lenDesti + 1;
    
    for (int i = 0; i < *lenDesti; i++){
        switch(*pDesti){
            case 0: *pDesti = '0'; break;
            case 1: *pDesti = '1'; break;
            case 2: *pDesti = '2'; break;
            case 3: *pDesti = '3'; break;
            case 4: *pDesti = '4'; break;
            case 5: *pDesti = '5'; break;
            case 6: *pDesti = '6'; break;
            case 7: *pDesti = '7'; break;
            case 8: *pDesti = '8'; break;
            case 9: *pDesti = '9'; break;
            case 10: *pDesti = 'A'; break;
            case 11: *pDesti = 'B'; break;
            case 12: *pDesti = 'C'; break;
            case 13: *pDesti = 'D'; break;
            case 14: *pDesti = 'E'; break;
            case 15: *pDesti = 'F'; break;
            default: 
                printf("\nerror: not in range hexa\n");
                return FALSE;
        }
        pDesti++;
    }
    
    pDesti = pDesti - (unsigned char)*lenDesti;
    
    /* swaps position */
    if (!swap(pDesti, lenDesti)){
        printf("\nerror: swap was wrong\n");
        return FALSE;
    }
    
    return TRUE;
}
