#ifndef _DECIMAL_TO_BCD_H_
#define _DECIMAL_TO_BCD_H_

#define TRUE    1
#define FALSE   0

int FUNC_convert(unsigned char *desti, unsigned char *source);
int FUNC_decimalToBCD(unsigned char *desti, int *source);


#endif