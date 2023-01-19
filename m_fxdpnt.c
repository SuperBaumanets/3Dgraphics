#include "m_fxdpnt.h"
#include <stdint.h>

fp32_t float2fp32(float num)
{
    return (fp32_t)(num * (1 << FSHIFT));
}

float fp322float(fp32_t num)
{
    return ((float) num) / (float)(1 << FSHIFT);
}

fp32_t addfp32(fp32_t term1, fp32_t term2)
{
    return(term1 + term2);
}

fp32_t difffp32(fp32_t minuend, fp32_t subtrahend)
{
    return(minuend - subtrahend);
}

fp32_t multfp32(fp32_t multiplier1, fp32_t multiplier2)
{
    fp32_t intprt1 = multiplier1 >> FSHIFT; //intact part
    fp32_t intprt2 = multiplier2 >> FSHIFT;

    printf("-------------------------\n");
    printf("multiplier1 = %d\n", multiplier1);
    printf("intprt1 = %d\n", intprt1);

    fp32_t frctprt1 = multiplier1 & ((1 << FSHIFT) - 1); //fractional part
    fp32_t frctprt2 = multiplier2 & ((1 << FSHIFT) - 1);
    printf("frctprt1 = %d\n", frctprt1);

    printf("-------------------------\n");

    return ( ((fp32_t)(intprt1 * intprt2) << FSHIFT) + ((fp32_t)(frctprt1 * frctprt2) >> FSHIFT) + (fp32_t)(intprt1 * frctprt2) + (fp32_t)(intprt2 * frctprt1));

}
