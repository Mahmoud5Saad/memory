#include <stdlib.h>


uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	int abs_data = abs(data);
	int i = 0;

	while(abs_data)
	{
		int reminder = abs_data % base;
	
		if(reminder >= 10)
		{
			*(ptr + i) = 65 + (reminder - 10) ;
			i++;
		}		
		
		else
		{
			*(ptr + i) = 48 + reminder;
			i++;
		}

		abs_data = abs_data / base;
	

	}

	
	if( i == 0)
	{
		*(ptr + i) = 0;
		i++;
	}


	if(data < 0 && base == 10) /*if data input is negative and desired base is decimal base*/
	{
		*(ptr+i) = '-';
		i++;	
	}

	*(ptr + i) = '\0'; /*Null terminator at the end*/
	
	
	uint8_t counter = 0;
	
	while ( *(ptr + counter) != '\0' )
	{
		counter++;
	}

	uint8_t length_Of_Converted_Data = counter + 1;

	ptr = my_reverse(ptr, length_Of_Converted_Data);
		
	return length_Of_Converted_Data;
	
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	int32_t num = 0;
	int32_t sign = 1;
 	int i = 0;
 
	if (*ptr == '-')
	{
		sign = -1;
		i++;
	}

	for (; i < digits; i++)
	{
		num = num*10 + *(ptr + i) - '0';
	}

	return sign*num;
}
