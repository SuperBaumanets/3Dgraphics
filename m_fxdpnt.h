#ifndef M_FXDPNT_H_INCLUDED
#define M_FXDPNT_H_INCLUDED

#include <stdint.h>

//Declarations and definitions
//=============================================================================================================================
#define FSHIFT 16                   //FSHIFT states how much bits will be after point.
                                    //Q15.16: 1 bit sign
                                    //       15 bits integer part
                                    //       16 bits for the fractional part
#define MAX (1 << FSHIFT)           //
#define MAX_FRACTION (MAX - 1)      //Max positive value
//=============================================================================================================================

typedef int32_t fp32_t;

//Functions
//================================================================================================================================================
//@brief 		Convert float to fixed point.
//@param num    Converted number
fp32_t float2fp32(float num);

//@brief 		Convert fixed point to float.
//@param num    Converted number
float fp322float(fp32_t num);

//@brief 		Addition 2 fixed point numbers.
//@param term1  first term
//@param term2  second term
fp32_t addfp32(fp32_t term1, fp32_t term2);

//@brief 		    Difference 2 fixed point numbers.
//@param minuend    minuend number
//@param subtrahend subtrahend number
fp32_t difffp32(fp32_t minuend, fp32_t subtrahend);


fp32_t multfp32(fp32_t multiplier1, fp32_t multiplier2);
//================================================================================================================================================

#endif // M_FXDPNT_H_INCLUDED
