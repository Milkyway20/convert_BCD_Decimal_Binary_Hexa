#include "strBinaryToDecimal.h"
#include <stdio.h>
#include <math.h>

_Bool strBinaryToDecimal(int *pDesti, unsigned char *pSource, int lenSour){
    /* check lenSour */
    if (lenSour <= 0){
        printf("\nerror: length of string is wrong\n");
        return FALSE;
    }
    
    /* check binary string */
    for (int i = 0; i < lenSour; i++){
        if (*pSource == '0'){
            *pSource = 0;
        }
        else if (*pSource == '1'){
            *pSource = 1;
        }
        else {
            printf("\nerror: This string is not binary string\n");
            return FALSE;
        }
        pSource++;
    }
    
    /* reset pSource */
    pSource = pSource - lenSour;
    
    /* convert */
    for (int i = 0; i < lenSour; i++){
        *pDesti += (int)(*pSource*pow(BINARY, 1.0*(lenSour-i-1)));
        pSource++;
    }
    
    return TRUE;
}
