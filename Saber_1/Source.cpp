


#include <iostream>

void dec_to_bin (const int value)
{
	if (value == 0) 
	{
		std::cout << "0" << std::endl;
		return;
	}
	if( value < 0)
	{
		int tmp = value * -1;
		int steps = (log(tmp) / log(2) + 2);
		int* result = new int[steps];
		result[steps - 1] = 1;
		for (int i = 0; tmp > 0; i++)
		{
			result[i] = !(tmp % 2);
			tmp = tmp / 2;
		}
		for(int i = 0; i < steps - 1; i++)
		{
			int cur = result[i] + 1;
			result[i] = cur % 2;
			if(cur / 2 == 0)
			{
				break;
			}
		}
		
		for (int i = steps - 1; i >= 0; i--)
			std::cout << result[i] << " ";
		std::cout << std::endl;
		delete[]result;
	}
	else
	{
		int steps = (log(value) / log(2) + 2);
		int* result = new int[steps];
		result[steps - 1] = 0;
		int tmp = value;

		for (int i = 0; tmp > 0; i++)
		{
			result[i] = tmp % 2;
			tmp = tmp / 2;
		}
		for (int i = steps - 1; i >= 0; i--)
			std::cout << result[i] << " ";
		std::cout << std::endl;
		delete[]result;
	}
	
	
}



int main()
{
	for(int i = - 128; i < 128; i ++)
	{
		dec_to_bin(i);
	}
		
}