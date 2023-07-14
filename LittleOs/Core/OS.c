#include "OS.h"

volatile unsigned char LittleHeart = 0;

/*!
 **********************************************************
 *@brief OS's Heart Function
 *
 *The function need be ported to timer for 1ms .
 *
 **********************************************************
 **/
void LittleHeartFunc(void)
{
	LittleHeart = 1;
}

/*!
 ***********************************************************
 *@brief OS dispatch Function
 *
 *The function need be ported to main function endless loop.
 *
 ***********************************************************
 **/
void OS(void)
{
	static unsigned char HeartCnt = 0;

	if(LittleHeart == 1)
	{
		HeartCnt++;
		LittleHeart = 0;
		OS_1ms();
		if ((HeartCnt % 2) == 0)
		{
			OS_2ms();
		}
		if ((HeartCnt % 4) == 1)
		{
			OS_4ms1();
		}
		if ((HeartCnt % 8) == 3)
		{
			OS_8ms3();
		}
		if ((HeartCnt % 8) == 7)
		{
			OS_8ms7();
		}
	}
	else
	{
		OS_Idle();
	}
}

