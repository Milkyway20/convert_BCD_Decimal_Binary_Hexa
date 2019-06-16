#include "strHexaToDecimal.h"
#include <stdio.h>
#include <math.h>

_Bool strHexaToDecimal(int *pDesti, unsigned char *pSource, int lenSour){
    /* check lenSour */
    if (lenSour <= 0){
        printf("\nerror: length of string is wrong\n");
        return FALSE;
    }
    
    /* check binary string */
    for (int i = 0; i < lenSour; i++){
        switch(*pSource){
            case '0': *pSource = 0; break;
            case '1': *pSource = 1; break;
            case '2': *pSource = 2; break;
            case '3': *pSource = 3; break;
            case '4': *pSource = 4; break;
            case '5': *pSource = 5; break;
            case '6': *pSource = 6; break;
            case '7': *pSource = 7; break;
            case '8': *pSource = 8; break;
            case '9': *pSource = 9; break;
            case 'A':
            case 'a': *pSource = 10; break;
            case 'B':
            case 'b': *pSource = 11; break;
            case 'C':
            case 'c': *pSource = 12; break;
            case 'D':
            case 'd': *pSource = 13; break;
            case 'E':
            case 'e': *pSource = 14; break;
            case 'F':
            case 'f': *pSource = 15; break;
            default:
                printf("\nerror: This string is not Hexa string\n");
                return FALSE;
        }
        pSource++;
    }
    
    /* reset pSource */
    pSource = pSource - lenSour;
    
    /* convert */
    for (int i = 0; i < lenSour; i++){
        *pDesti += (int)(*pSource*pow(HEXA, 1.0*(lenSour-i-1)));
        pSource++;
    }
    
    return TRUE;
}
