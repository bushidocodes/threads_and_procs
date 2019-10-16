/*
 * Created on Sat Sep 07 2019:19:22:9
 * Created by Ratnadeep Bhattacharya
 *
 * Copyright (c) 2019 George Washington University
 */

#include "fibonacci.h"

unsigned int
fibonacci(unsigned int n)
{
	switch (n)
	{
	case 0:
		return 0;
		break;
	case 1:
		return 1;
		break;
	default:
		return fibonacci(n - 1) + fibonacci(n - 2);
		break;
	}
}
