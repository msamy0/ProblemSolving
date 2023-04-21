/*
 * LED Flasher
 * toggles LED every 1ms according to user input between 1 - 50 ms
 * user update will take effect in the current runnign cycle
 * user input represent the ON period or OFF period, so the full ON/OFF cycle takes (2 x Input)ms
 * NOTE : Code is not optimized yet
 * */
#include <stdlib.h>
#include <stdio.h>

typedef unsigned char              uint8;
typedef unsigned short int         uint16;
typedef unsigned int               uint32;
typedef unsigned long long         uint64;
typedef signed char                sint8;
typedef signed short int           sint16;
typedef signed int                 sint32;

uint8 LedFalsher(uint8 OnOffInterval);

int main()
{
	uint8 input = 0;
	uint8 result = 0xff;
	while(1)
	{
		scanf(" %d",(int*)(&input) ); //assum it comes every 1ms to get the new interval from user
		result = LedFalsher(input);
		printf("Output of function is %d \n",result);
		fflush(NULL);
	}


		//some code to delay the reset of 1ms
}

uint8 LedFalsher(uint8 OnOffInterval)
{
	static uint8 LastOnOffInterval= 0;
	static uint8 CounterFromLastIntervalEdit = 0;
	static uint8 lastOnOffValue = 0; // the inital case is the inverse of this  value (due to first if condition action on first Call of this function)

	if (OnOffInterval > 50 || OnOffInterval < 1) 						// exceed boundaries
	{
		if (CounterFromLastIntervalEdit > 0)
			CounterFromLastIntervalEdit--;								// decrement counter by 1

		else //if it is 0
		{
			lastOnOffValue = !lastOnOffValue;							//toggle the LED flag, however it will not get effect on hardware due to 0xff mandatory error return
			CounterFromLastIntervalEdit = LastOnOffInterval;			//keep the counter running incase you got rubbish between valid values [ie: 5-5-5-99-5-5]
		}

		return 0xff; //return error status while keeping
	}
	else // correct boundaries
	{
		/*
		 * if the counter equals 0, it means one of two cases:
		 * 1- this is the first call of the function
		 * 2- the function is called at last count tick and have to toggle the LED and update the interval
		 * */
		if (CounterFromLastIntervalEdit == 0)
		{
			LastOnOffInterval = OnOffInterval; 							// set new interval equals to the function input
			CounterFromLastIntervalEdit = OnOffInterval; 				// decrement the the counter to mimic 1ms elapsed period
			CounterFromLastIntervalEdit--;								// decrement counter by 1
			lastOnOffValue = !lastOnOffValue; 							//toggle LED
		}

		/*
		 * else the counter greater than 0, it means one of three cases:
		 * 1- new interval is set (new interval > last interval)
		 * 2- new interval is set (new interval < last interval)
		 * 3- the interval didn't change (new interval = last interval)
		 * */
		else
		{
			uint8 TempDifference = 0;									// make a temp variable to hold the difference between last and new intervals

			if (OnOffInterval > LastOnOffInterval)						/* 1- new interval is set (new interval > last interval) */
			{
				TempDifference  = OnOffInterval - LastOnOffInterval;	// get the difference
				CounterFromLastIntervalEdit += TempDifference;			// add TempDifference to current counter value, to shift toggle time by the new difference
				CounterFromLastIntervalEdit--;							// decrement counter by 1
				LastOnOffInterval = OnOffInterval;						// update LastOnOffInterval
				//go to return line
			}

			else if (OnOffInterval < LastOnOffInterval)					/*2- new interval is set (new interval < last interval)*/
			{
				TempDifference = LastOnOffInterval - OnOffInterval;		// get the difference

				/* check whether the difference exceeds the counter or not */
				if (TempDifference > CounterFromLastIntervalEdit)		//if TempDifference exceeds Counter,then force toggle now
				{
					lastOnOffValue = !lastOnOffValue; 					// toggle now as you exceed the new limit
					CounterFromLastIntervalEdit = OnOffInterval; 		// decrement the the counter
					CounterFromLastIntervalEdit--;						//decrement counter by 1
					LastOnOffInterval = OnOffInterval; 					// set new interval
					//go to return line
				}

				else if (TempDifference < CounterFromLastIntervalEdit)	//if TempDifference doesn't exceeds Counter, then just update it
				{
					CounterFromLastIntervalEdit = CounterFromLastIntervalEdit - TempDifference;
					CounterFromLastIntervalEdit--;
					LastOnOffInterval = OnOffInterval;
					//go to return line
				}
			}

			else 														/*3- the interval didn't change (new interval = last interval)*/
			{
				CounterFromLastIntervalEdit--;
				//go to return line
			}

		}
		return lastOnOffValue;
	}

}
